/**
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT WARRANTY OF ANY KIND; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * MIT License for more details.
 */

/**
 * @file Queue.hpp
 *
 * @brief Base class for queue
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <cstddef>

namespace algorithms {

template<typename T>
class Queue {
public:
    virtual ~Queue() = default;

    /**
     * Enqueue item to the queue.
     *
     * @param item The reference to the item.
     */
    virtual void
    push(const T& item)
        = 0;

    /**
     * Dequeue item from the queue.
     *
     * @return The item object.
     */
    virtual T
    pop()
        = 0;

    /**
     * Returns reference to the first element in the queue.
     *
     * @return Reference to the first element.
     */
    virtual T&
    front()
        = 0;

    /**
     * Returns constant reference to the first element in the queue.
     *
     * @return Constant reference to the first element.
     */
    virtual const T&
    front() const = 0;

    /**
     * Returns reference to the last element in the queue.
     *
     * @return Reference to the last element.
     */
    virtual T&
    back()
        = 0;

    /**
     * Returns constant reference to the last element in the queue.
     *
     * @return Constant reference to the last element.
     */
    virtual const T&
    back() const = 0;

    /**
     * Check for queue is empty.
     *
     * @return The flag which indicated that queue is empty.
     */
    [[nodiscard]] virtual bool
    empty() const = 0;

    /**
     * Return the number of elements.
     *
     * @return The number of elements.
     */
    [[nodiscard]] virtual std::size_t
    size() const = 0;
};

} // namespace algorithms
