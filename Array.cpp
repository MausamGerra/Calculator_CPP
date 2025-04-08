// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept> // for std::out_of_bounds exception
#include <iostream>
#include <algorithm>
#include "Array.h"
#include "Base_Array.h"
//
// Array
//
template <typename T>
Array<T>::Array() : Base_Array<T>(), data_(nullptr), cur_size_(0), max_size_(0)
{
    std::cout << "This is a default constructor in Array.cpp" << std::endl;
}

//
// Array (size_t)
//
template <typename T>
Array<T>::Array(size_t length) : Base_Array<T>(length), data_(new T[length]), cur_size_(length), max_size_(length)
{
    data_ = new T[length];
    cur_size_ = length;
    max_size_ = length;
    std::cout << "This constructor passes value of size 'length' " << length << " in Array.cpp" << std::endl;
    std::cout << "Array: Current Size = " << cur_size_ << ", Array: Max Size = " << max_size_ << std::endl;
}

//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array(size_t length, T fill) : Base_Array<T>(length), data_(new T[length]), cur_size_(length), max_size_(length)
{
    data_ = new T[length];
    cur_size_ = length;
    max_size_ = length;
    std::cout << "Array: Current Size = " << cur_size_ << ", Array: Max Size = " << max_size_ << std::endl;
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
Array<T>::Array(const Array &array) : Base_Array<T>(array.cur_size_), data_(new T[array.cur_size_]), cur_size_(array.cur_size_), max_size_(array.cur_size_)
{
    std::cout << "Array: Current Size = " << cur_size_ << ", Array: Max Size = " << max_size_ << std::endl;
    for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = array.data_[i];
    }
    std::cout << "Copy constructor data array of length " << cur_size_ << " to data_ as ";

    for (size_t i = 0; i < cur_size_; i++)
    {
        std::cout << data_[i];
    }
    std::cout << std::endl;
}

//
// ~Array
//
template <typename T>
Array<T>::~Array()
{
    delete[] data_;
    std::cout << "Deleted the arr." << std::endl;
}

//
// operator =
//
template <typename T>
const Array<T> &Array<T>::operator=(const Array &rhs)
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
T &Array<T>::operator[](size_t index)
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}

//
// operator []
//
template <typename T>
const T &Array<T>::operator[](size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}

//
// get
//
template <typename T>
T Array<T>::get(size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[index];
}

//
// set
//
// template <typename T>
// void Array<T>::set(size_t index, T value)
// {
//     if (index > cur_size_ && cur_size_ != 0)
//     {
//         std::cerr << "Error: Array::set() - Index out of bounds: " << index << std::endl;
//         throw std::out_of_range("Array::set() - Index out of bounds");
//     }
//     if (data_ == nullptr && index == 0)
//     {
//         resize(1);
//     }
//     data_[index] = value;
// }
template <typename T>
void Array<T>::set(size_t index, T value)
{
    // Resize if index is out of current bounds
    if (index >= cur_size_)
    {
        // Resize to accommodate the new index
        resize(index + 1); // +1 because index is zero-based
    }

    if (data_ == nullptr)
    {
        std::cerr << "Error: Array::set() - Internal data pointer is null after resize." << std::endl;
        throw std::runtime_error("Array::set() - Internal error");
    }

    data_[index] = value;
}

//
// resize
//
template <typename T>
void Array<T>::resize(size_t new_size)
{
    if (new_size > 0)
    {
        T *new_data = new T[new_size];

        // std::cout << "New size = " << new_size << ", Current size = " << cur_size_ << std::endl;
        size_t copy_size = std::min(new_size, cur_size_);
        if (data_ != nullptr && copy_size > 0)
        {
            for (size_t i = 0; i < copy_size; i++)
            {
                new_data[i] = data_[i];
            }
        }
        delete[] data_;
        data_ = new_data;
        cur_size_ = new_size;
        max_size_ = new_size;
    }
    else
    {
        delete[] data_;
        data_ = nullptr;
        cur_size_ = 0;
        max_size_ = 0;
    }
}

//
// find (char)
//
template <typename T>
int Array<T>::find(T value) const
{
    return find(value, 0);
}

//
// find (char, size_t)
//
template <typename T>
int Array<T>::find(T val, size_t start) const
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
bool Array<T>::operator==(const Array &rhs) const
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
bool Array<T>::operator!=(const Array &rhs) const
{
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array<T>::fill(T value)
{
    for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = value;
    }
}