//
// Created by Josh Levy-Kramer on 27/03/2020.
//

#include <cmath>
#include <iostream>

template <typename F, unsigned N>
class nth_derivative
{
    using prev_derivative= nth_derivative<F,  N-1>;
public:
    nth_derivative(const F& f, double h) : h(h), fp(f, h) {}

    double operator()(double x) const {
        return ( fp(x) - fp(x-h) ) / h;
    }
private:
    double h;
    prev_derivative fp;
};

// Specialisation of `nth_derivative` class for N = 1 (to stop infinite recursion)
template <typename F>
class nth_derivative<F, 1>{
    public:
        nth_derivative(const F& f, double h) : h(h), f(f) {}

        double operator()(double x) const {
            return ( f(x) - f(x-h) ) / h;
        }

    private:
        double h;
        const F f;
};

// 2*cos(x) + x^2
class cos_func {
    public:
        cos_func () = default;
        double operator()(double x) const {
            return (2*std::cos(x)) + (x*x);
        }
};

int main() {
    double dd = nth_derivative<cos_func, 2>(cos_func(), 0.01)(1);
    std::cout << dd;

    return 0;
}