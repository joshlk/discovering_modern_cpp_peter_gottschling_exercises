//
// Created by Josh Levy-Kramer on 2019-01-22.
//

// Make a small program that creates arrays on the stack (fixed-size arrays) and arrays on the heap (using allocation).
// Use valgrind to check what happens when you do not delete them correctly.

#include <vector>

int main() {
    // Array on the stack (array of 10 ints)
    int x[10];

    // Array on the heap
    int *y = new int[10];

}