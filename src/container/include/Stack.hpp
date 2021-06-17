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
 * @file Stack.hpp
 *
 * @brief Base class for stack
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

namespace algorithms {

/**
 * Interface class for stack implementations.
 */
template<typename T>
class Stack {
public:
    virtual ~Stack() = default;

    /**
     * Push item to the stack.
     *
     * @param item The reference to the item.
     */
    virtual void
    push(const T& item)
        = 0;

    /**
     * Pop item from the stack.
     *
     * @return The item object.
     */
    virtual T
    pop()
        = 0;

    /**
     * Check for stack is empty.
     *
     * @return The flag which indicated that stack is empty.
     */
    [[nodiscard]] virtual bool
    empty() const = 0;
};

} // namespace algorithms
