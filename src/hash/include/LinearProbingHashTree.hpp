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
 * @file LinearProbingHashTree.hpp
 *
 * @brief Linear probing hash tree algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Hash.hpp"

#include <optional>
#include <array>

namespace algorithms {

/**
 * Basic hash tree implementation with linear probing resolve collision method.
 */
template<typename Key, typename Value, std::size_t N = 1000 /* magick number */>
class LinearProbingHashTree {
public:
    using KeyValuePair = std::pair<Key, Value>;
    using KeyValuePairOrNull = std::optional<KeyValuePair>;

    void
    put(const Key& key, const Value& value)
    {
        hash<Key> hasher{};
        std::size_t n = hasher(key) % N;
        for (std::size_t p = n ? (n - 1) % N : N - 1; _basket[n].has_value(); n = (n + 1) % N) {
            if (n == p) {
                throw std::runtime_error{"Tree is overfull"};
            }
            if (std::get<Key>(_basket[n].value()) == key) {
                break;
            }
        }
        _basket[n].emplace(key, value);
    }

    Value
    get(const Key& key)
    {
        hash<Key> hasher{};
        for (std::size_t n = hasher(key); _basket[n].has_value(); n = (n + 1) % N) {
            const auto& [k, v] = _basket[n].value();
            if (k == key) {
                return v;
            }
        }
        throw std::runtime_error{"Item not found"};
    }

private:
    std::array<KeyValuePairOrNull, N> _basket;
};

} // namespace algorithms
