#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string data = "10 20.5 30";
    int a;
    double b;
    int c;
    string data2 = "abc def";
    
    //istringstream sin(data); // one way to place the string "data" into the stream
    istringstream sin;
    sin.str(data);
    sin >> a >> b >> c;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    sin.clear();            // if we reuse sin, then we need clear it before re-using
    sin.str(data2);         // placed a different string in the stream - this will be ignored if .clear() is not done first

    string s1, s2;
    sin >> s1 >> s2;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << "-----------------------------" << endl;
    /********************/
    ostringstream sout;
    string output;

    sout << a << " " << b << " " << c << " ";
    output = sout.str();
    cout << output << endl;

    sout.str("");       // This "resets" sout to create a new string. Remove this and see what happens
    sout << 40 << " " << 50;
    output = sout.str();
    cout << output << endl;
}