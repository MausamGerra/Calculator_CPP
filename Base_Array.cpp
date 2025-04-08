// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept> // for std::out_of_bounds exception
#include <iostream>
#include <algorithm>
#include "Base_Array.h"
//
// Array
//
template <typename T>
Base_Array<T>::Base_Array()
{
    data_ = nullptr;
    cur_size_ = 0;
    max_size_ = 0;
    std::cout << "This is a default constructor in Base_Array.cpp" << std::endl;
}

//
// Array (size_t)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length)
{
    data_ = new T[length];
    cur_size_ = length;
    max_size_ = length;
    std::cout << "This constructor passes value of size 'length' " << length << " in Base_Array.cpp" << std::endl;
    std::cout << "Base Array: Current Size = " << cur_size_ << ", Base Array: Max Size = " << max_size_ << std::endl;
}

//
// Array (size_t, char)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill)
{
    data_ = new T[length];
    cur_size_ = length;
    max_size_ = length;
    std::cout << "Base Array: Current Size = " << cur_size_ << ", Base Array: Max Size = " << max_size_ << std::endl;
    std::cout << "Filled the data array of length " << length << " with " << std::endl;
    for (size_t i = 0; i < length; i++)
    {
        data_[i] = fill;
        std::cout << data_[i] << " at position " << i << std::endl;
    }
}

//
// Array (const Array &)
//
template <typename T>
Base_Array<T>::Base_Array(const Base_Array &base_array)
{
    std::cout << "Base Array: Current Size = " << base_array.cur_size_ << ", Base Array: Max Size = " << base_array.max_size_ << std::endl;
    data_ = new T[base_array.cur_size_];
    cur_size_ = base_array.cur_size_;
    max_size_ = base_array.cur_size_;
    std::cout << "Copy constructor data of Base array of length " << cur_size_ << " to data_ as ";
    for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = base_array.data_[i];
        std::cout << data_[i];
    }
    std::cout << "" << std::endl;
}

//
// ~Array
//
template <typename T>
Base_Array<T>::~Base_Array()
{
    delete[] data_;
    std::cout << "Deleted the arr." << std::endl;
}

//
// operator =
//
template <typename T>
const Base_Array<T> &Base_Array<T>::operator=(const Base_Array &rhs)
{
    if (this != &rhs)
    {
        delete[] data_;
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.cur_size_;
        if (cur_size_ > 0)
        {
            data_ = new T[cur_size_];
            for (size_t i = 0; i < cur_size_; i++)
            {
                data_[i] = rhs.data_[i];
            }
        }
        else
        {
            data_ = nullptr;
        }
    }
    return *this;
}

//
// operator []
//
template <typename T>
T &Base_Array<T>::operator[](size_t index)
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Base_Array: Index out of bounds");
    }
    return data_[index];
}

//
// operator []
//
template <typename T>
const T &Base_Array<T>::operator[](size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Base_Array: Index out of bounds");
    }
    return data_[index];
}

//
// get
//
template <typename T>
T Base_Array<T>::get(size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Base_Array: Index out of bounds");
    }
    return data_[index];
}

//
// set
//
template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Base_Array: Index out of bounds");
    }
    data_[index] = value;
}

//
// find (char)
//
template <typename T>
int Base_Array<T>::find(T value) const
{
    return find(value, 0);
}

//
// find (char, size_t)
//
template <typename T>
int Base_Array<T>::find(T val, size_t start) const
{
    for (size_t i = start; i < cur_size_; i++)
    {
        if (data_[i] == val)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array<T>::operator==(const Base_Array &rhs) const
{
    if (cur_size_ != rhs.cur_size_)
    {
        return false;
    }

    for (size_t i = 0; i < cur_size_; i++)
    {
        if (data_[i] != rhs.data_[i])
        {
            return false;
        }
    }
    return true;
}

//
// operator !=
//
template <typename T>
bool Base_Array<T>::operator!=(const Base_Array &rhs) const
{
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Base_Array<T>::fill(T value)
{
    for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = value;
    }
}