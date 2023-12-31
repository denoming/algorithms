﻿/**
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT WARRANTY OF ANY KIND; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * MIT License for more details.
 */

/**
 * @file ResizableArrayQueue.hpp
 *
 * @brief Resizable array queue implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <stdexcept>

#include "Queue.hpp"

namespace algorithms {

/** Default capacity for the empty queue */
constexpr std::size_t DefaultCapacity = 15;

template<typename T>
class ResizableArrayQueue : public Queue<T> {
public:
    ResizableArrayQueue()
        : _size{0}
        , _epos{0}
        , _dpos{0}
        , _data{nullptr}
    {
        resize(DefaultCapacity);
    }

    ~ResizableArrayQueue() override
    {
        if (_data) {
            delete[] _data;
        }
    }

    void
    push(const T& item) override
    {
        if (_epos == _size) {
            resize(_size * 2);
        }
        _data[_epos++] = item;
    }

    T
    pop() override
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        if (_epos - _dpos == _size / 4) {
            resize(_size / 2);
        }

        T item = _data[_dpos++];
        if (_dpos == _epos) {
            _dpos = 0;
            _epos = 0;
        }
        return item;
    }

    T&
    front()
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _data[_dpos];
    }

    const T&
    front() const
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _data[_dpos];
    }

    T&
    back()
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _data[_epos - 1];
    }

    const T&
    back() const
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _data[_epos - 1];
    }

    [[nodiscard]] bool
    empty() const override
    {
        return (_epos == _dpos);
    }

    [[nodiscard]] std::size_t
    size() const
    {
        return (_epos > _dpos) ? _epos - _dpos : 0;
    }

private:
    void
    resize(std::size_t size)
    {
        T* data = new T[size];
        std::move(_data + _dpos, _data + _epos, data);
        delete[] _data;
        _epos = _epos - _dpos;
        _dpos = 0;
        _data = data;
        _size = size;
    }

private:
    std::size_t _epos;
    std::size_t _dpos;
    std::size_t _size;
    T* _data;
};

} // namespace algorithms
