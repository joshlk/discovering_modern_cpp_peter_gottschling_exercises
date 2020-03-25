//
// Created by Josh Levy-Kramer on 25/03/2020.
//

#include <memory>
#include <vector>
#include <exception>


class EmptyStack: public std::exception
{
    virtual const char* what() const throw()
    {
        return "The stack is empty.";
    }
} emptystack;

class FullStack: public std::exception
{
    virtual const char* what() const throw()
    {
        return "The stack is full.";
    }
} fullstack;

template <typename T>
class GenericStack {

    public:
        GenericStack (unsigned int max_size): max_size(max_size) {
            stack = std::unique_ptr<T[]>(new T[max_size]);
            size = 0;
        }

        T& top () {
            if (size == 0) {
                throw emptystack;
            }
            return stack[size-1];
        }

        void pop () {
            if (size == 0) {
                throw emptystack;
            }
            size = size -1;
        }

        void push (T e) {
            if (size == max_size) {
                throw fullstack;
            }

            size = size + 1;
            stack[size] = e;
        }

        void clear () {
            if (size == 0) {
                throw emptystack;
            }

            size = 0;
        }

        auto sizeOf () {
            return size;
        }

        bool full () {
            return size == max_size;
        }

        bool empty () {
            return size == 0;
        }

    private:
        unsigned int max_size;
        unsigned int size;
        std::unique_ptr<T[]> stack; // Using a unique_pointer array instead of vector to make it harder
};

// Explicit instantiation of class for different types
template class GenericStack<double>;
template class GenericStack<bool>;
template class GenericStack<std::vector<double>>;


int main () {
    GenericStack<bool> bool_stack = GenericStack<bool>(10);
    bool_stack.push(1);

    return 0;
}