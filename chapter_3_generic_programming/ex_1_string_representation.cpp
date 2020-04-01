//
// Created by Josh Levy-Kramer on 24/03/2020.
//

#include <iostream>
#include <string>
#include <sstream>

using std::string;

template <typename T>
string to_string (const T &e) {
    std::stringstream ss;
    string str;
    ss << e;
    ss >> str;
    return str;
}

template string to_string<string> (const string&);
template string to_string<int> (const int&);
template string to_string<double> (const double&);

int main () {
    std::cout << to_string(100);

    return 0;
}