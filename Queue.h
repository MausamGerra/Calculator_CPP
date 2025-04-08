// -*- C++ -*-

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>
#include <cstddef>
#include "Array.h"

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
    /// Type definition of the type.
    typedef T type;

    /**
     * @class empty_exception
     *
     * Exception thrown to indicate the Queue is empty.
     */
    class empty_exception : public std::exception
    {
    public:
        /// Default constructor.
        empty_exception(void)
            : std::exception() {}

        /**
         * Initializing constructor.
         *
         * @param[in]      msg         Error message.
         */
        empty_exception(const char *msg)
            : std::exception()
        {
            this->message = msg;
        }

    private:
        const char *message = nullptr;
    };

    /// Default constructor.
    Queue(void);

    /// Copy constructor.
    Queue(const Queue &s);

    /// Destructor.
    ~Queue(void);

    /**
     * Assignment operator
     *
     * @param[in]      rhs           Right-hand side of operator
     * @return         Reference to self
     */
    const Queue &operator=(const Queue &rhs);

    /**
     * Push a new \a element onto the queue. The element is inserted
     * after all the other elements in the list.
     *
     * @param[in]      element       Element to add to the end of the list
     */
    void print(T element);

    /**
     * Push a new \a element onto the queue. The element is inserted
     * after all the other elements in the list.
     *
     * @param[in]      element       Element to add to the end of the list
     */
    void enqueue(T element);

    /**
     * Remove the first element from the queue.
     *
     * @exception      empty_exception    The queue is empty.
     */
    void dequeue(void);

    /**
     * Test if the queue is empty
     *
     * @retval         true          The queue is empty
     * @retval         false         The queue is not empty
     */
    bool is_empty(void) const;

    /**
     * Number of element on the stack.
     *
     * @return         Size of the stack.
     */
    size_t size(void) const;

    /// Remove all elements from the stack.
    void clear(void);

private:
    // add member variable here
    Array<T> data_;
    size_t cur_size_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
// #include "Queue.cpp"

#endif // !defined _QUEUE_H_
