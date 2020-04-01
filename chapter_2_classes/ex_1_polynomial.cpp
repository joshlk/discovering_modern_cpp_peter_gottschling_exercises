
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <initializer_list>

// Exercise 1, 2 and 3


class Polynomial {
    // Degree=size-1

    public:
        // Constructor as same name as class itself
        // Providing a `member initialisation list` auto sets value
        // Has default constructor of 1 degree
        Polynomial (int degree = 0): degree(degree), coefficients(std::vector<double>(degree + 1)) {
        }

        // Constructor when specifying coefficients
        // Pass by pointer - does not copy
        Polynomial (const std::vector<double>  coefficients): degree(coefficients.size() - 1), coefficients(coefficients) {
        }

        // Use of initializer list. i.e. variable number of arguments length constructor
        explicit Polynomial (std::initializer_list<double> coefficients_init): degree(coefficients_init.size() - 1) {
             coefficients = std::vector<double>(coefficients_init);  // Explicit conversion
        }

        // Pass by pointer - does not copy
        void set_coefficients(const std::vector<double>&  coefficients_new) {
            if ( degree != (coefficients_new.size()-1) ) {
                throw std::invalid_argument( "Number of coefficients must be one more than degree of Polynomial" );
            }

            coefficients = coefficients_new;
        }

         Polynomial operator+(Polynomial p_2) {
            auto degree_new = std::max(degree, p_2.degree);
            Polynomial p_3 = Polynomial(degree_new);

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

        auto print() {
            std::stringstream output;

            output << "p =";

            for (int i = 0; i < coefficients.size(); i++) {
                output << " +" << coefficients[i] << "*" << "x_" << i << std::endl;
            }
            output << std::endl;

            return output.str();
        }

        // Destructor
        ~Polynomial() {
            degree = -1;
            coefficients.clear();
        }

        // -- Exercise 2: Move assigment
        // Whereas the goal of the copy constructor and copy assignment is to make a copy of one object to another,
        // the goal of the move constructor and move assignment is to move ownership of the resources from one object
        // to another (which is much less expensive than making a copy).
        // Best description found: https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners
        // Best description of lvalues and rvalues: https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c

        // In reality all these are equivalent to the default declared behaviour (automatically added by the compiler)
        // and are not necessary

        // Copy constructor - deep copy
        // This method constructs a new object. p is the old object
        // std::vector automatically deep copies so this is not required but included for demonstration
        Polynomial(const Polynomial& p): degree(p.degree) {
            std::cout << "Copy constructor" << std::endl;
            coefficients = p.coefficients; // std::vectors deep copy on assignment
        }

        // Move constructor - shallow copy (no copy)
        // Argument is a rvalue reference. i.e. can take temporary/non-addressed objects as an argument that are mutable
        Polynomial(Polynomial&& p) noexcept : degree(p.degree) {
            std::cout << "Move constructor" << std::endl;
            coefficients = std::move(p.coefficients);
            p.degree = -1; // The source must be left in an "empty" state
        }

        // Copy assignment
        // Notice that a reference is returned and the argument is also a lvalue reference
        Polynomial& operator=(const Polynomial& p) {
            std::cout << "Copy assignment" << std::endl;
            degree = p.degree;
            coefficients = p.coefficients; // std::vectors deep copy on assignment
            return *this;
        }

        // Move assignment
        // Argument is a rvalue reference
        Polynomial& operator=(Polynomial&& p) {
            std::cout << "Move assignment" << std::endl;
            degree = p.degree;
            coefficients = std::move(p.coefficients);
            p.degree = -1; // Leave source in "empty" state
            return *this;
        }


    protected:
        int degree;
        std::vector<double> coefficients;

};

// -- Usage
void construct_with_degree_and_add() {
    // -- Construct with degree and add
    Polynomial p_1(2);
    Polynomial p_2(4);

    p_1.set_coefficients({1, 1, 1});
    p_2.set_coefficients({1, 2, 3, 4, 5});

    auto p_3 = p_1 + p_2;

    std::cout << p_3.print();
}

void default_constructor() {
    // Default constructor. Gives zero for coefficients
    Polynomial p_4;
    std::cout << p_4.print();
}

void initializer_list() {
    // Use initializer list. i.e. variable length constructor
    Polynomial p_5{4, 3, 2, 1};
    std::cout << p_5.print();
}

Polynomial polynomial_degree_2(double c0, double c1, double c2) {
    Polynomial p1{c0, c1, c2};
    return p1;
}

Polynomial polynomial_from_old(Polynomial p) {
    return p;
}

void copy_and_move_semantics() {
    Polynomial p1;
    Polynomial p2;
    p1 = p2; // Copy assignment

    Polynomial p3{1,2,3};
    Polynomial p4(p3); // Copy constructor

    Polynomial p5;
    p5 = polynomial_degree_2(0,1,2); // Move assignment on function return

    Polynomial p6;
    Polynomial p7;
    p7 = polynomial_from_old(p6); // Move constructor. p6 is passed by value to the function `polynomial_from_old`


}

// -- Main
int main() {
    construct_with_degree_and_add();
    default_constructor();
    initializer_list();
    copy_and_move_semantics();

    return 0;
}


