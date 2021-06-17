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
 * @file ChainingHashTree.hpp
 *
 * @brief Chaining hash tree.hpp algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Hash.hpp"

#include <algorithm>
#include <forward_list>
#include <array>
#include <optional>

namespace algorithms {

/**
 * Basic hash tree implementation with chaining resolve collision method.
 */
template<typename Key, typename Value, std::size_t N = 97 /* magick number */>
class ChainingHashTree {
public:
    using KeyValuePair = std::pair<Key, Value>;
    using Chain = std::forward_list<KeyValuePair>;

    void
    put(const Key& key, const Value& value)
    {
        Chain& chain = byChain(key);
        if (chain.empty()) {
            chain.emplace_front(key, value);
        }

        auto it = find(chain, key);
        if (it == chain.end()) {
            chain.emplace_front(key, value);
        }
        else {
            std::get<Value>(*it) = value;
        }
    }

    Value
    get(const Key& key)
    {
        Chain& chain = byChain(key);
        if (chain.empty()) {
            throw std::runtime_error{"Item not found"};
        }

        auto it = find(chain, key);
        if (it == chain.cend()) {
            throw std::runtime_error{"Item not found"};
        }
        return std::get<Value>(*it);
    }

private:
    Chain&
    byChain(const Key& key)
    {
        hash<Key> hasher{};
        return _chains[hasher(key) % N];
    }

    typename Chain::iterator
    find(Chain& chain, const Key& key)
    {
        return std::find_if(chain.begin(), chain.end(), [&key](const KeyValuePair& kv) {
            return (std::get<Key>(kv) == key);
        });
    }

private:
    std::array<Chain, N> _chains;
};

} // namespace algorithms
