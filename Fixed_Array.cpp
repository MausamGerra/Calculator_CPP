// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include <stdexcept> // for std::out_of_bounds exception
#include <iostream>
#include <algorithm>
#include "Fixed_Array.h"
//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array() : Base_Array<T>(N)
{
    std::cout << "This is a default constructor in Fixed_Array.cpp." << std::endl;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N> &arr) : Base_Array<T>(arr)
{
    std::cout << "Copy constructor data array of length " << this->size() << " in Fixed_Array.cpp" << std::endl;
    /*for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = array.data_[i];
        std::cout << data_[i];
    }*/
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, M> &arr) : Base_Array<T>(arr)
{
    size_t copy_arr = std::min(N, M);

    for (size_t i = 0; i < copy_arr; i++)
    {
        (*this)[i] = arr[i];
    }

    std::cout << "Copy constructor with different size. Copied in Fixed_Array.cpp" << copy_arr << " elements." << std::endl;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(T fill) : Base_Array<T>(N, fill)
{
    std::cout << "Filled the array with values in Fixed_Array." << std::endl;
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::~Fixed_Array()
{
    std::cout << "Calling Parent Destructor.. to DESTROYYYYY" << std::endl;
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array<T, N> &Fixed_Array<T, N>::operator=(const Fixed_Array<T, N> &rhs)
{
    if (this != &rhs)
    {
        Base_Array<T>::operator=(rhs); // const Array<T> &Array<T>::operator=(const Array &rhs)
    }

    return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array<T, N> &Fixed_Array<T, N>::operator=(const Fixed_Array<T, M> &rhs)
{
    size_t copy_arr = std::min(N, M);

    for (size_t i = 0; i < copy_arr; i++)
    {
        (*this)[i] = rhs[i];
    }

    return *this;
}