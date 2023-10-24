/*
 * Name: Aaron Marshall
 * USERID: amarsh32
 * Program Description: This program implements a circular doubly-linked list with a sentinel node.
 * The list stores strings and provides various methods to manipulate the data.
 */

#include "dlist.hpp"
#include <iostream>
using namespace std;

// Returns the next node in the list
Dnode* Dnode::Next() {
    return flink;
}

// Returns the previous node in the list
Dnode* Dnode::Prev() {
    return blink;
}

// Default constructor for Dlist
Dlist::Dlist() {
    sentinel = new Dnode;         // Create the sentinel node
    sentinel->flink = sentinel;   // Initialize the sentinel's forward link to itself
    sentinel->blink = sentinel;   // Initialize the sentinel's backward link to itself
    size = 0;                     // Initialize the list size to 0
}

// Copy constructor for Dlist
Dlist::Dlist(const Dlist &d) {
    sentinel = new Dnode;
    sentinel->flink = sentinel;
    sentinel->blink = sentinel;
    size = 0;

    // Copy the content of the given list to the new list
    for (Dnode *n = d.sentinel->flink; n != d.sentinel; n = n->flink) {
        Push_Back(n->s);
    }
}

// Assignment overload for Dlist
Dlist& Dlist::operator= (const Dlist &d) {
    if (this != &d) { // Check for self-assignment
        Clear(); // Clear the current list

        // Copy the content of the given list to the current list
        for (Dnode *n = d.sentinel->flink; n != d.sentinel; n = n->flink) {
            Push_Back(n->s);
        }
    }
    return *this;
}

// Destructor for Dlist
Dlist::~Dlist() {
    Clear();          // Clear the list
    delete sentinel;  // Delete the sentinel node
}

// Clears the list
void Dlist::Clear() {
    while (!Empty()) {
        Pop_Front(); // Remove the elements from the list until it's empty
    }
}

// Returns true if the list is empty, false otherwise
bool Dlist::Empty() const {
    return sentinel->flink == sentinel;
}

// Returns the size of the list
size_t Dlist::Size() const {
    return size;
}

// Adds a new element with a string value to the front of the list
void Dlist::Push_Front(const std::string &s) {
    Dnode *n = new Dnode;
    n->s = s;
    n->flink = sentinel->flink;
    n->blink = sentinel;
    sentinel->flink->blink = n;
    sentinel->flink = n;
    size++;
}

// Adds a new element with a string value to the back of the list
void Dlist::Push_Back(const std::string &s) {
    Dnode *n = new Dnode;
    n->s = s;
    n->flink = sentinel;
    n->blink = sentinel->blink;
    sentinel->blink->flink = n;
    sentinel->blink = n;
    size++;
}

// Removes and returns the first element in the list
std::string Dlist::Pop_Front() {
    if (Empty()) {
        throw std::runtime_error("Trying to pop from an empty list");
    }
    Dnode *n = sentinel->flink;
    string s = n->s;
    sentinel->flink = n->flink;
    n->flink->blink = sentinel;
    delete n;
    size--;
    return s;
}

// Removes and returns the last element in the list
std::string Dlist::Pop_Back() {
    if (Empty()) {
        throw std::runtime_error("Trying to pop from an empty list");
    }
    Dnode *n = sentinel->blink;
    string s = n->s;
    sentinel->blink = n->blink;
    n->blink->flink = sentinel;
    delete n;
    size--;
    return s;
}

// Returns a pointer to the first node in the list
Dnode* Dlist::Begin() const {
    return sentinel->flink;
}

// Returns a pointer to one past the last node in the list
Dnode* Dlist::End() const {
    return sentinel;
}

// Returns a pointer to the last node in the list
Dnode* Dlist::Rbegin() const {
    return sentinel->blink;
}

// Returns a pointer to one before the first node in the list
Dnode* Dlist::Rend() const {
    return sentinel;
}

// Inserts a new node with string value 's' before the given node 'n'
void Dlist::Insert_Before(const std::string &s, Dnode *n) {
    Dnode *newNode = new Dnode;
    newNode->s = s;
    newNode->flink = n;
    newNode->blink = n->blink;
    n->blink->flink = newNode;
    n->blink = newNode;
    size++;
}

// Inserts a new node with string value 's' after the given node 'n'
void Dlist::Insert_After(const std::string &s, Dnode *n) {
    Dnode *newNode = new Dnode;
    newNode->s = s;
    newNode->flink = n->flink;
    newNode->blink = n;
    n->flink->blink = newNode;
    n->flink = newNode;
    size++;
}

// Erases the given node 'n' from the list
void Dlist::Erase(Dnode *n) {
    if (n == sentinel) {
        throw std::runtime_error("Cannot erase sentinel node");
    }
    n->blink->flink = n->flink;
    n->flink->blink = n->blink;
    delete n;
    size--;
}

