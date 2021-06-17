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
 * @file FixedArrayStack.hpp
 *
 * @brief Fixed array stack implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <stdexcept>

#include "Stack.hpp"

namespace algorithms {

static constexpr std::size_t DefaultCapacity = 10;

/**
 * Fixed size stack implementation.
 */
template<typename T>
class FixedArrayStack : public Stack<T> {
public:
    explicit FixedArrayStack(std::size_t size = DefaultCapacity)
        : _n{0}
        , _s{size}
    {
#ifndef NDEBUG
        if (size == 0) {
            throw std::invalid_argument{"Capacity is invalid"};
        }
#endif
        _data = new T[size];
    }

    ~FixedArrayStack() override
    {
        delete[] _data;
    }

    void
    push(const T& item) override
    {
#ifndef NDEBUG
        if (_n == _s) {
            throw std::overflow_error{"Stack is overflow"};
        }
#endif
        _data[_n++] = item;
    }

    T
    pop() override
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::underflow_error{"Stack is empty"};
        }
#endif
        return _data[--_n];
    }

    [[nodiscard]] bool
    empty() const override
    {
        return (_n == 0);
    }

private:
    std::size_t _n;
    std::size_t _s;
    T* _data;
};

} // namespace algorithms
