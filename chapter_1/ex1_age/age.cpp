//
// Created by Josh Levy-Kramer on 11/03/2018.
//

#include <iostream>
#include <fstream>

int main() {
    // Print to screen
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Please input your age and then press return" << std::endl;

    // Take input
    int age;
    std::cin >> age;

    // Print to screen
    std::cout << "Your age is.. " << age << std::endl;

    // Write to file
    std::cout << "Path to file output?" << std::endl;
    std::string path;
    std::cin >> path;
    std::cout << "Output to: " << path << std::endl;

    // Write to file
    std::ofstream file(path);
    file << "Age is:" << age << std::endl;
    file.close();

    return 0;
}