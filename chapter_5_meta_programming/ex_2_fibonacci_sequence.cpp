//
// Created by Josh Levy-Kramer on 05/04/2020.
//

#include <iostream>

template <int N>
struct FibonacciSequence {
    constexpr FibonacciSequence(): S() {
        S[0] = 0;
        S[1] = 1;

        for (int i = 2, xn = 0; i <= N; i++) {
            S[i] = S[i-1] + S[i-2];
        }
    }
    int S[N+1];  // Default initialisation of zeros
};

int main() {
    const int N = 10;
    constexpr auto FS = FibonacciSequence<N>();

    for (int i = 0, xn = 0; i <= N; i++) {
        std::cout << "x" << i << " = " << FS.S[i] << std::endl;
    }

    static_assert(FS.S[0] == 0, "");

    return  0;
}