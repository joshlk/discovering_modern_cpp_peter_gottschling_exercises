//
// Created by Josh Levy-Kramer on 26/03/2020.
//

// Exercise 5 and 6

#include <iostream>
#include <stdexcept>

class OddIterator {
public:
    OddIterator (int start = 1): i(start) {
        if (!check_odd_number(start)) {
            throw std::domain_error("Start number `start` should be an odd number");
        }
    }

    OddIterator (OddIterator const &src): i(src.i) {}

    bool check_odd_number (int num) {
        return ((num + 1) % 2) == 0;
    }

    void increment () {
        i += 2;
    }

    // Pre-increment
    // "Pre-increment and pre-decrement operators increments or decrements the value of the object
    // and returns a reference to the result."
    OddIterator& operator++() {
        increment();
        return *this;
    }

    // Post-increment
    // "Post-increment and post-decrement creates a copy of the object, increments or decrements
    // the value of the object and returns the copy from before the increment or decrement."
    // "int is a dummy parameter to differentiate between the two. it is always 0"
    OddIterator operator++(int) {
        OddIterator tmp(*this);
        operator++(); // prefix-increment this instance
        return tmp;   // return value before increment
    }

    // Dereference operator - i.e. get the value this container points to
    int& operator* () {
        return i;
    }

    // Equality operators
    bool operator== (OddIterator e2) {
        return i == e2.i;
    }

    bool operator!= (OddIterator e2) {
        return i != e2.i;
    }

    // Move semantics
    OddIterator(OddIterator&& src): i(src.i) {}


    OddIterator& operator=(const OddIterator& src) {
        i = src.i;
        return *this;
    }

    OddIterator& operator=(OddIterator&& src) {
        i = src.i;
        return *this;
    }

    ~OddIterator () {}

protected:
    int i;
};

class OddRange {
public:
    OddRange(int start = 1, int end = 1): start_i(start), end_i(end) {
    }

    OddIterator begin () {
        static OddIterator oi = OddIterator(start_i-2);
        return oi;
    }

    OddIterator end () {
        static OddIterator oi = OddIterator(end_i-2);
        return oi;
    }

private:
    int start_i;
    int end_i;
};


int main () {
    std::cout << *(++OddIterator(3));

    for (int i : OddRange(7, 27)) {
        std::cout << i << std::endl;
    }

    return 0;
}
