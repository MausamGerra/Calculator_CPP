// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.
#include "Stack.h"
//
// size
//
template <typename T>
inline size_t Stack<T>::size() const
{
    return cur_size_;
}

//
// top
//
template <typename T>
T Stack<T>::top() const
{
    if (is_empty())
    {
        throw empty_exception("Stack is empty");
    }
    return data_.get(cur_size_ - 1);
}

//
// is_empty
//
template <typename T>
inline bool Stack<T>::is_empty(void) const
{
    return (cur_size_ == 0);
}
