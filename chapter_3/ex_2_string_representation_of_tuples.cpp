//
// Created by Josh Levy-Kramer on 25/03/2020.
//

#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

template <typename T>
string to_string (const T &e) {
    std::stringstream ss;
    string str;
    ss << e;
    ss >> str;
    return str;
}

template <typename T>
string _to_tuple_string (T a) {
    return to_string(a);
}

template <typename T, typename ...P>
string _to_tuple_string (T a, P ...b) {
    // `_to_tuple_string` when has more than one argument recursively calls this function
    // Removing an argument at a time
    // When its down to the last argument it calls the overloaded `_to_tuple_string` which only accepts one argument
    string str = to_string(a) + ", " + _to_tuple_string(b...);
    return str;
}

template <typename T, typename ...P>
string to_tuple_string (T a, P ...b) {
    string str = "(" + _to_tuple_string(a, b...) + ')';
    return str;
}


int main () {
    // Prints: "(1, 2, 3.1, 4)"
    string s = to_tuple_string(1, "2", 3.1, 4);
    std::cout << s;

    return 0;
}