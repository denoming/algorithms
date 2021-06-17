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
 * @file TernarySearchTries.hpp
 *
 * @brief Ternary search tries algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <optional>

namespace algorithms {

class TernarySearchTries {
public:
    using Keys = std::vector<std::string>;

    TernarySearchTries();

    ~TernarySearchTries();

    [[nodiscard]] bool
    has(std::string_view key);

    int
    get(std::string_view key);

    void
    put(std::string_view key, int value);

    [[nodiscard]] Keys
    keys() const;

    [[nodiscard]] Keys
    keysWithPrefix(std::string_view prefix) const;

    [[nodiscard]] Keys
    keysThatMatch(std::string_view pattern) const;

    [[nodiscard]] std::string
    longestPrefixOf(std::string_view prefix) const;

    void
    erase(std::string_view key);

    void
    clear();

private:
    struct Node {
        explicit Node(char ch)
            : ch{ch}
            , value{}
        {
        }

        Node(char ch, int value)
            : ch{ch}
            , value{value}
        {
        }

        ~Node()
        {
            delete lh;
            delete mi;
            delete rh;
        }

        [[nodiscard]] bool
        hasChildren() const
        {
            return lh || mi || rh;
        }

        [[nodiscard]] bool
        hasValue() const
        {
            return value.has_value();
        }

        char ch;
        std::optional<int> value;
        Node* mi{nullptr};
        Node* lh{nullptr};
        Node* rh{nullptr};
    };

private:
    Node*
    put(Node* node, std::string_view key, int value, std::size_t dimension);

    Node*
    get(Node* node, std::string_view key, std::size_t dimension) const;

    std::size_t
    search(Node* node, std::string_view key, std::size_t dimension, std::size_t length) const;

    void
    collect(Node* node, std::string& prefix, Keys& keys) const;

    void
    collect(Node* node,
            std::string& prefix,
            std::string_view pattern,
            std::size_t dimension,
            Keys& keys) const;

    Node*
    erase(Node* node, std::string_view key, std::size_t dimension);

private:
    Node* _root;
};

} // namespace algorithms
