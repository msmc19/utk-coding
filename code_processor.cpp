
/*
 * Name: Aaron Marshall
 * USERID: amarsh32
 * Program Description:This program manages a system for users to enter codes, accumulate points, and redeem prizes. Users can also add and remove phone numbers associated with their accounts, and the system can output its current state to a file.
 */

#include "code_processor.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

// djb_hash function: generates a hash from the given string
unsigned int djb_hash(const string &str) {
    unsigned int hash = 5381;
    for (char c : str) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

// New_Prize: adds a new prize to the system
bool Code_Processor::New_Prize(const string &id, const string &description, int points, int quantity) {
    if (Prizes.find(id) != Prizes.end() || points <= 0 || quantity <= 0) {
        return false;
    }

    Prize *prize = new Prize{id, description, points, quantity};
    Prizes[id] = prize;
    return true;
}

// New_User: creates a new user in the system
bool Code_Processor::New_User(const string &username, const string &realname, int starting_points) {
    if (Names.find(username) != Names.end() || starting_points < 0) {
        return false;
    }

    User *user = new User{username, realname, starting_points, set<string>()};
    Names[username] = user;
    return true;
}

// Delete_User: removes a user from the system
bool Code_Processor::Delete_User(const string &username) {
    auto user_it = Names.find(username);
    if (user_it == Names.end()) {
        return false;
    }

    User *user = user_it->second;
    for (const string &phone : user->phone_numbers) {
        Phones.erase(phone);
    }

    Names.erase(user_it);
    delete user;
    return true;
}

// Add_Phone: associates a phone number with a user
bool Code_Processor::Add_Phone(const string &username, const string &phone) {
    auto user_it = Names.find(username);
    if (user_it == Names.end() || Phones.find(phone) != Phones.end()) {
        return false;
    }

    User *user = user_it->second;
    user->phone_numbers.insert(phone);
    Phones[phone] = user;
    return true;
}

// Remove_Phone: disassociates a phone number from a user
bool Code_Processor::Remove_Phone(const string &username, const string &phone) {
    auto user_it = Names.find(username);
    if (user_it == Names.end()) {
        return false;
    }

    User *user = user_it->second;
    auto phone_it = user->phone_numbers.find(phone);
    if (phone_it == user->phone_numbers.end()) {
        return false;
    }

    user->phone_numbers.erase(phone_it);
    Phones.erase(phone);
    return true;
}

// Show_Phones: displays all phone numbers associated with a user
string Code_Processor::Show_Phones(const string &username) const {
    auto user_it = Names.find(username);
    if (user_it == Names.end()) {
        return "BAD USER";
    }

    User *user = user_it->second;
    ostringstream ss;
    for (const string &phone : user->phone_numbers) {
        ss << phone << endl;
    }
    return ss.str();
}

// Enter_Code: allows a user to enter a code and gain points if the code is valid
int Code_Processor::Enter_Code(const string &username, const string &code) {
    auto user_it = Names.find(username);
    if (user_it == Names.end() || Codes.find(code) != Codes.end()) {
        return -1;
    }

    unsigned int hash = djb_hash(code);
    int points = 0;
    if (hash % 17 == 0) {
        points = 10;
    } else if (hash % 13 == 0) {
        points = 3;
    }

    if (points > 0) {
        User *user = user_it->second;
        user->points += points;
        Codes.insert(code);
    }

    return points;
}

// Text_Code: allows a user to enter a code via their associated phone number
int Code_Processor::Text_Code(const string &phone, const string &code) {
    auto phone_it = Phones.find(phone);
    if (phone_it == Phones.end()) {
        return -1;
    }

    User *user = phone_it->second;
    return Enter_Code(user->username, code);
}

// Mark_Code_Used: marks a code as used in the system
bool Code_Processor::Mark_Code_Used(const string &code) {
    unsigned int hash = djb_hash(code);
    if (Codes.find(code) != Codes.end() || (hash % 17 != 0 && hash % 13 != 0)) {
        return false;
    }

    Codes.insert(code);
    return true;
}

// Balance: returns the current point balance for a user
int Code_Processor::Balance(const string &username) const {
    auto user_it = Names.find(username);
    if (user_it == Names.end()) {
        return -1;
    }

    User *user = user_it->second;
    return user->points;
}

// Redeem_Prize: allows a user to redeem a prize with their accumulated points
bool Code_Processor::Redeem_Prize(const string &username, const string &prize_id) {
    auto user_it = Names.find(username);
    auto prize_it = Prizes.find(prize_id);

    if (user_it == Names.end() || prize_it == Prizes.end()) {
        return false;
    }

    User *user = user_it->second;
    Prize *prize = prize_it->second;

    if (user->points < prize->points || prize->quantity <= 0) {
        return false;
    }

    user->points -= prize->points;
    prize->quantity--;

    if (prize->quantity == 0) {
        Prizes.erase(prize_it);
        delete prize;
    }

    return true;
}

// Code_Processor destructor: deallocates memory for all users and prizes
Code_Processor::~Code_Processor() {
    for (auto &name_pair : Names) {
        delete name_pair.second;
    }

    for (auto &prize_pair : Prizes) {
        delete prize_pair.second;
    }
}

// Write: outputs the current state of the system to a file
bool Code_Processor::Write(const string &filename) const {
    ofstream outfile(filename);

    if (!outfile.is_open()) {
        return false;
    }

    // Write prizes
    for (const auto &prize_pair : Prizes) {
        Prize *prize = prize_pair.second;
        outfile << "PRIZE " << prize->id << " " << prize->points << " " << prize->quantity << " " << prize->description << endl;
    }

    // Write users and their phones
    for (const auto &name_pair : Names) {
        User *user = name_pair.second;
        outfile << "ADD_USER " << user->username << " " << user->points << endl;
        for (const std::string &phone : user->phone_numbers) {
            outfile << "ADD_PHONE " << user->username << " " << phone << endl;
        }
    }

    // Write used codes
    for (const string &code : Codes) {
        outfile << "MARK_USED " << code << endl;
    }

    outfile.close();
    return true;
}
