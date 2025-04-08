// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.
#include "Queue.h"
//
// size
//
template <typename T>
inline size_t Queue<T>::size() const
{
    return cur_size_;
}

//
// is_empty
//
template <typename T>
inline bool Queue<T>::is_empty(void) const
{
    return (cur_size_ == 0);
}
