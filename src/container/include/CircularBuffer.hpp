#pragma once

#include <array>
#include <optional>

namespace algorithms {

template<typename T, std::size_t N>
class CircularBuffer {
public:
    using ValueOpt = std::optional<T>;

    CircularBuffer()
        : _full{false}
        , _head{0}
        , _tail{0}
    {}

    void put(T&& value)
    {
        _values[_head] = std::make_optional<T>(std::move(value));
        advance();
    }

    ValueOpt get()
    {
        if (empty()) {
            return std::nullopt;
        }

        ValueOpt value = std::move(_values[_tail]);
        retreat();
        return value;
    }

    void reset()
    {
        _full = false;
        _head = 0;
        _tail = 0;

        for (ValueOpt& value : _values) {
            value.reset();
        }
    }

    [[nodiscard]]
    bool empty() const
    {
        return !_full && (_head == _tail);
    }

    [[nodiscard]]
    bool full() const
    {
        return _full;
    }

    [[nodiscard]]
    std::size_t capacity() const
    {
        return N;
    }

    [[nodiscard]]
    std::size_t size() const
    {
        if (!_full) {
            if (_head != _tail) {
                return (_head > _tail) ? (_head - _tail) : (N + _head - _tail);
            } else {
                return 0;
            }
        }
        return N;
    }

private:
    void advance()
    {
        if (_full) {
            _tail = (_tail + 1) % N;
        }
        _head = (_head + 1) % N;
        _full = (_head == _tail);
    }

    void retreat()
    {
        _tail = (_tail + 1) % N;
        _full = false;
    }

private:
    bool _full;
    std::size_t _head;
    std::size_t _tail;
    std::array<ValueOpt, N> _values;
};

}