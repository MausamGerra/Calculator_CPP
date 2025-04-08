// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Base_Array.h"
//
// size
//
template <typename T>
inline size_t Base_Array<T>::size() const
{
    return cur_size_;
}

//
// max_size
//
template <typename T>
inline size_t Base_Array<T>::max_size() const
{
    return max_size_;
}