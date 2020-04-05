//
// Created by Josh Levy-Kramer on 02/04/2020.
//

#include <iostream>
#include <typeinfo>

// ---- remove_reference
// Overload for a normal type, type reference and rvalue type reference
template <typename T>
struct remove_reference {
    using type = T;
};

template <typename T>
struct remove_reference<T&> {
    using type = T;
};

template <typename T>
struct remove_reference<T&&> {
    using type = T;
};

template <typename T>
struct remove_reference<T*> {
    using type = T;
};

// ---- add_reference
template <typename T>
struct add_reference {
    using type = T&;
};

template <typename T>
struct add_reference<T&> {
    using type = T&;
};

template <typename T>
struct add_reference<T&&> {
    using type = T&;
};

template <typename T>
struct add_reference<T*> {
    using type = T&;
};

int main() {
    // -- remove_reference
    // Could use `using` syntax here. Taken from cpp reference
    typedef int&& rval_int;
    typedef remove_reference<int>::type A;
    typedef remove_reference<int&>::type B;
    typedef remove_reference<int&&>::type C;
    typedef remove_reference<rval_int>::type D;
    typedef remove_reference<int*>::type E;

    std::cout << std::boolalpha;
    std::cout << "typedefs of int:" << std::endl;
    std::cout << "A: " << std::is_same<int,A>::value << std::endl;
    std::cout << "B: " << std::is_same<int,B>::value << std::endl;
    std::cout << "C: " << std::is_same<int,C>::value << std::endl;
    std::cout << "D: " << std::is_same<int,D>::value << std::endl;
    std::cout << "E: " << std::is_same<int,E>::value << std::endl << std::endl;

    // All these are executed at compile time. Will throw error at compile time if not true
    static_assert(std::is_same<int,A>::value, "");
    static_assert(std::is_same<int,B>::value, "");
    static_assert(std::is_same<int,C>::value, "");
    static_assert(std::is_same<int,D>::value, "");
    static_assert(std::is_same<int,E>::value, "");
    //static_assert(std::is_same<int,double>::value, ""); // does not compile


    // -- add_reference
    typedef add_reference<int>::type A2;    // int&
    typedef add_reference<int&>::type B2;   // int&
    typedef add_reference<int&&>::type C2;  // int&
    typedef add_reference<int*>::type D2;   // int*&

    std::cout << std::boolalpha;
    std::cout << "typedefs of int&:" << std::endl;
    //std::cout << "A: " << typeid(tst::trans(A2)).name() << std::endl;
    std::cout << "A: " << std::is_same<int&,A2>::value << std::endl;
    std::cout << "B: " << std::is_same<int&,B2>::value << std::endl;
    std::cout << "C: " << std::is_same<int&,C2>::value << std::endl;
    std::cout << "D: " << std::is_same<int&,D2>::value << std::endl;

    return 0;
}