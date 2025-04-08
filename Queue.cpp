// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Queue
//
#include <stdexcept> // for std::out_of_bounds exception
#include <iostream>
#include "Queue.h"

template <typename T>
Queue<T>::Queue(void) : data_(), cur_size_(0)
{
    std::cout << "Calling default constructor in Queue class. I don't know what else to do :)" << std::endl;
}

//
// Queue
//
template <typename T>
Queue<T>::Queue(const Queue &queue) : data_(queue.data_), cur_size_(queue.cur_size_)
{
    std::cout << "Copy Queue using Parent Array copy constructor." << std::endl;
    std::cout << "queue.cur_size_ = " << cur_size_ << std::endl;
    std::cout << "queue.data_ = ";

    for (size_t i = 0; i < data_.size(); i++)
    {
        std::cout << data_.get(i);
    }

    std::cout << std::endl;
}

//
// ~Queue
//
template <typename T>
Queue<T>::~Queue(void)
{
    std::cout << "Parent Destructor will be destroying here in Queue as well" << std::endl;
}

//
// enqueue
//
template <typename T>
void Queue<T>::enqueue(T element)
{
    data_.set(cur_size_, element);
    cur_size_++;
    // std::cout << "current size = " << cur_size_ << std::endl;
    data_.resize(cur_size_);
    // std::cout << "resized current size = " << cur_size_ << std::endl;
}

//
// dequeue
//
template <typename T>
void Queue<T>::dequeue(void)
{
    if (is_empty())
    {
        throw empty_exception("Queue is empty");
    }
    cur_size_--;
    data_.resize(cur_size_);
}

//
// operator =
//
template <typename T>
const Queue<T> &Queue<T>::operator=(const Queue &rhs)
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
void Queue<T>::clear(void)
{
    data_.resize(0);
}
