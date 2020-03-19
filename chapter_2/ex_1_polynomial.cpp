
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <initializer_list>


class polynomial {
    // Degree=size-1

    public:
        // Constructor as same name as class itself
        // Providing a `member initialisation list` auto sets value
        // Has default constructor of 1 degree
        polynomial (int degree = 0): degree(degree), coefficients(std::vector<double>(degree+1)) {
        }

        // Constructor when specifying coefficients
        // Pass by pointer - does not copy
        explicit polynomial (const std::vector<double>&  coefficients): degree(coefficients.size()-1), coefficients(coefficients) {
        }

        // Use of initializer list. i.e. variable number of arguments length constructor
        explicit polynomial (std::initializer_list<double> coefficients_init) {
             coefficients = std::vector<double>(coefficients_init);  // Explicit conversion
        }

        // Pass by pointer - does not copy
        void set_coefficients(const std::vector<double>&  coefficients_new) {
            if ( degree != (coefficients_new.size()-1) ) {
                throw std::invalid_argument( "Number of coefficients must be one more than degree of polynomial" );
            }

            coefficients = coefficients_new;
        }

         polynomial operator+(polynomial p_2) {
            auto degree_new = std::max(degree, p_2.degree);
            polynomial p_3 = polynomial(degree_new);

            for (int i = 0; i < degree_new; i++) {
                double c_i = 0;
                if ((i < degree) and (i < p_2.degree)) {
                    c_i = coefficients[i] + p_2.coefficients[i];
                } else if ((i >= degree) and (i < p_2.degree)) {
                    c_i = p_2.coefficients[i];
                } else if ((i < degree) and (i >= p_2.degree)) {
                    c_i = coefficients[i];
                } else {
                    throw std::exception();
                }

                p_3.coefficients[i] = c_i;
            }

            return p_3;
        }

        auto print () {
            std::stringstream output;

            output << "p =";

            for (int i = 0; i < coefficients.size(); i++) {
                output << " +" << coefficients[i] << "*" << "x_" << i << std::endl;
            }
            output << std::endl;

            return output.str();
        }


    private:
        int degree;
        std::vector<double> coefficients;

};

int main() {
    // -- Construct with degree and add
    polynomial p_1(2);
    polynomial p_2(4);

    p_1.set_coefficients({1, 1, 1});
    p_2.set_coefficients({1, 2, 3, 4, 5});

    auto p_3 = p_1 + p_2;

    std::cout << p_3.print();

    // Default constructor. Gives zero for coefficients
    polynomial p_4;
    std::cout << p_4.print();

    // Use initializer list. i.e. variable length constructor
    polynomial p_5{4, 3, 2, 1};
    std::cout << p_5.print();

    return 0;
}