// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
#include <stdexcept>
#include <iostream>
#include "Stack.h"

template <typename T>
Stack<T>::Stack(void) : data_(), cur_size_(0)
{
    std::cout << "Calling default constructor in Stack class. I don't know what else to do :)" << std::endl;
}

//
// Stack
//
template <typename T>
Stack<T>::Stack(const Stack &stack) : data_(stack.data_), cur_size_(stack.cur_size_)
{
    std::cout << "Copy Stack using Parent Array copy constructor." << std::endl;
    std::cout << "stack.cur_size_ = " << cur_size_ << std::endl;
    std::cout << "stack.data_ = ";

    for (size_t i = 0; i < data_.size(); i++)
    {
        std::cout << data_.get(i);
    }

    std::cout << std::endl;
}

//
// ~Stack
//
template <typename T>
Stack<T>::~Stack(void)
{
    std::cout << "Parent Destructor will be destroying here in Stack as well" << std::endl;
}

//
// push
//
template <typename T>
void Stack<T>::push(T element)
{
    data_.set(cur_size_, element);
    cur_size_++;
    // std::cout << "current size = " << cur_size_ << std::endl;
    data_.resize(cur_size_);
    // std::cout << "resized current size = " << cur_size_ << std::endl;
}

//
// pop
//
template <typename T>
void Stack<T>::pop(void)
{
    if (is_empty())
    {
        throw empty_exception("Stack is empty");
    }
    cur_size_--;
    data_.resize(cur_size_);
}

//
// operator =
//
template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack &rhs)
{
    if (this != &rhs)
    {
        data_ = rhs.data_;
    }

    return *this;
}

//
// clear
//
template <typename T>
void Stack<T>::clear(void)
{
    data_.resize(0);
}
