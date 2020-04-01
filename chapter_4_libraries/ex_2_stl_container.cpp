//
// Created by Josh Levy-Kramer on 01/04/2020.
//

#include <map>
#include <string>
#include <iostream>
#include <algorithm>


int main() {
    std::map<std::string, unsigned long>telephone_numbers = {
            {"john", 7123123},
            {"jane", 2134454},
            {"jamie", 123456789},
            {"joan", 3847538}
    };

    std::cout << "John exists: " << telephone_numbers["john"] << std::endl;
    std::cout << "Kate does not but given default value: " << telephone_numbers["kate"] << std::endl;

    auto john = telephone_numbers.find("john");
    std::cout << "Found John: " << john->second << std::endl;

    // Search by value - find easy 1234... number
    for (auto it = telephone_numbers.begin(); it != telephone_numbers.end(); ++it)
        if (it->second == 123456789) std::cout << "Found whos got number 1234...: " << it->first << std::endl;

    auto louisa = telephone_numbers.find("louisa");
    std::cout << "Louis doesn't exist";
    assert(louisa == telephone_numbers.end());  // Louisa not found so returns `end`

    return 0;
}