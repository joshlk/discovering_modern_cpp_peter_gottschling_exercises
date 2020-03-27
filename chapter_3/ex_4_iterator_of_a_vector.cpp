//
// Created by Josh Levy-Kramer on 25/03/2020.
//

#include <memory>
#include <iostream>

template <typename T>
class vector {
    // ------ BEGINNING: from https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/vector_template.cpp
    void check_size(int that_size) const { assert(my_size == that_size); }
    void check_index(int i) const { assert(i >= 0 && i < my_size); }
public:
    explicit vector(int size)
            : my_size(size), data( new T[my_size] )
    {}

    vector()
            : my_size(0), data(0)
    {}

    vector(const vector& that)
            : my_size(that.my_size), data(new T[my_size])
    {
        std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
    }

    vector& operator=(const vector& that)
    {
        check_size(that.my_size);
        std::copy(&that.data[0], &that.data[that.my_size], &data[0]);
        return *this;
    }

    int size() const { return my_size; }

    const T& operator[](int i) const
    {
        check_index(i);
        return data[i];
    }

    T& operator[](int i)
    {
        check_index(i);
        return data[i];
    }

    vector operator+(const vector& that) const
    {
        check_size(that.my_size);
        vector sum(my_size);
        for (int i= 0; i < my_size; ++i)
            sum[i] = data[i] + that[i];
        return sum;
    }
public:
    int                   my_size;
    std::unique_ptr<T[]>  data;
    // ------ END: from github

    // ------ BEGINNING: Own work
private:
    // Type definitions. Create new types here
    using iterator = T * ;
    using const_iterator = const T * ;

public:

    iterator begin () {
        return &data[0];
    }

    const_iterator begin () const {
        return &data[0];
    }

    iterator end () {
        return &data[my_size];
    }

    const_iterator end () const {
        return &data[my_size];
    }
};

// Func `accumulate_array` from book
template <typename T>
T accumulate_array(T *a, T *a_end) {
    T sum(0);
    for (; a != a_end; ++a) {
        sum += *a;
    }
    return sum;
}

int main () {
    vector<int> v(3);
    v[0] = 9;
    v[1] = 1;
    v[2] = 3;
    std::cout << v[0] << "," << v[1] << "," << v[2] << std::endl;
    std::cout << accumulate_array(v.begin(), v.end()) << std::endl;

    std::sort(v.begin(), v.end());
    std::cout << v[0] << "," << v[1] << "," << v[2] << std::endl;

    return 0;
}