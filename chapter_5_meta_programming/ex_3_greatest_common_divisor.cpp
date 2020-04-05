//
// Created by Josh Levy-Kramer on 05/04/2020.
//

#include <iostream>

//function gcd(a, b):
//if b = 0 return a
//else return gcd(b, a mod b)

template <typename I>
I gcd(I a, I b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


// Meta version
template <int B, int A>
struct gcd_meta {
            static const int A_mod_B = A % B;
            static const int value = gcd_meta<A_mod_B, B>::value;
};

// When b=0 then value=A
// i.e. to branch you must use template overloading (conditional statements are eagerly evaluated at compile time)
template <int A>
struct gcd_meta<0, A> {
    static const int value = A;
};


int main() {
    const int a = 8, b = 12;

    // Generic function - run at run time
    std::cout << gcd(a, b) << std::endl;

    // Consts expresion - run at compile time
    constexpr int result = gcd_meta<a, b>::value;
    std::cout << result << std::endl;

    return 0;
}