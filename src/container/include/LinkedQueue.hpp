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
 * @file LinkedQueue.hpp
 *
 * @brief Linked queue implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <stdexcept>

#include "Queue.hpp"

namespace algorithms {

template<typename T>
class LinkedQueue : public Queue<T> {
public:
    LinkedQueue()
        : _first{nullptr}
        , _last{nullptr}
        , _size{0}
    {
    }

    ~LinkedQueue()
    {
        while (_first) {
            auto* n = _first->next;
            delete _first;
            _first = n;
        }
    }

    void
    push(const T& item) override
    {
        auto* n = _last;
        _last = new Node{item};
        if (empty()) {
            _first = _last;
        }
        else {
            n->next = _last;
        }
        _size++;
    }

    T
    pop() override
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        auto* n = _first;
        _first = n->next;
        T item = n->value;
        delete n;
        _size--;
        return item;
    }

    T&
    front() override
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _first->value;
    }

    const T&
    front() const override
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _first->value;
    }

    T&
    back() override
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _last->value;
    }

    const T&
    back() const
    {
#ifndef NDEBUG
        if (empty()) {
            throw std::runtime_error{"Queue is empty"};
        }
#endif
        return _last->value;
    }

    [[nodiscard]] bool
    empty() const override
    {
        return (_size == 0);
    }

    [[nodiscard]] std::size_t
    size() const override
    {
        return _size;
    }

private:
    struct Node {
        explicit Node(const T& value)
            : value{value}
            , next{nullptr}
        {
        }

        T value;
        Node* next;
    };

private:
    Node* _first;
    Node* _last;
    std::size_t _size;
};

} // namespace algorithms
