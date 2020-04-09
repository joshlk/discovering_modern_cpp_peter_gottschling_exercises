//
// Created by Josh Levy-Kramer on 05/04/2020.
//

#include <vector>

class my_vector {
public:
    typedef double value_type;

    my_vector( int n ) {
        V = std::vector<double, n>;
    }
    // Copy Constructor from type itself
    my_vector(const my_vector& V_scr ): V(V_scr.V) {}

    // Constructor from generic vector
    template <typename Vector>
    my_vector( Vector& V_scr ): V(V_scr.V) {};

    // Assignment operator
    my_vector& operator=( my_vector const& V_scr ) {
        V = V_scr.V;
        return *this;
    }

    // Assignment for generic Vector
    template <typename Vector>
    my_vector& operator=( Vector const& v ) {
        V = v;
        return *this;
    }

    // get operator
    value_type& operator() ( int i ) {
        return V[i];
    }

    int size() const {
        return V.size();
    }

    // get operator
    value_type operator() ( int i ) const {
        return V[i];
    }

private:
    std::vector<double> V;
};

// Dont understand what is required here ¯\_(ツ)_/¯
//template <typename Scalar, typename Vector>
//class scalar_times_vector_expression {
//    return
//};
//
//
//template <typename Scalar, typename Vector>
//scalar_times_vector_expressions<Scalar, Vector>
//operator*( Scalar const& s, Vector const& v )
//{
//    return scalar_times_vector_expressions<Scalar, Vector>( s, v );
//}

int main() {
    return 0;
}