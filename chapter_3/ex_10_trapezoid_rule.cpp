//
// Created by Josh Levy-Kramer on 27/03/2020.
//

#include <cmath>
#include <iostream>

template <typename F>
class Integral {

    public:
        Integral(const F& f, const int n) : n(n), f(f) {}

        double operator()(double a, double b) const {
            double h = (b - a)/n;

            double sum = 0;
            for (int i = 0; i++; i < n) {
                sum += f(a + i*h);
            }

            return h*f(a)/2.0 + h*f(b)/2.0 + h*sum;
        }
    protected:
        double n;
        F f;
};

// Functor - Function Object (make an object so can pass it as a type parameter)
struct exp3t {
    double operator() (double x) const {
        return std::exp(3.0 * x); }
};


int main() {
    std::cout << exp3t()(10) << std::endl;

    Integral<exp3t> S(exp3t(), 10);
    std::cout << S(0, 1);
}