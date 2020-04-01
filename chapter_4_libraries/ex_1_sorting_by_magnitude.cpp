//
// Created by Josh Levy-Kramer on 01/04/2020.
//

#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<double> seq = {-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};

    // Sort by magnitude (ascending)
    sort(seq.begin(), seq.end(), [](int x, int y){return abs(x) < abs(y);});

    // Print values
    for (auto i: seq) {
        std::cout << i << ", ";
    }

    return 0;
}