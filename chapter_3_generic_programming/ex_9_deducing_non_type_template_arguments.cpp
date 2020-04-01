//
// Created by Josh Levy-Kramer on 27/03/2020.
//

// write a function array_size that accepts a C array of arbitrary type and size as a reference
// and returns the size of that array. The actual function argument can be omitted since we are
// only interested in its type. Do you remember? We threatened this exercise in Section 1.8.7.1.
// On the other hand, we revealed the trickiest part of it in the meantime.

#include <iostream>

// Pass array by reference
template <typename T, int Size>
int array_size(T (&x)[Size]) {
    // Return size of array
    return Size;
}

int main() {
    int array[10];

    // Neither inferred
    std::cout << array_size<int, 10>(array);

    // Both inferred
    std::cout << array_size(array);

    return 0;
}