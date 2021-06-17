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
 * @file DepthPostOrderNoRecTraverse.hpp
 *
 * @brief Depth post-order traverse algorithm implementation (without recursion)
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <stack>
#include <functional>

namespace algorithms {

/**
 * Depth post-order traversal of tree without recursion.
 *
 * See full description in @file DepthPostOrderTraverse.hpp
 */
template<typename Node>
class DepthPostOrderNoRecTraverser {
public:
    using Callback = std::function<void(const typename Node::KeyType&, typename Node::ValueType&)>;

    explicit DepthPostOrderNoRecTraverser(Node* root)
        : _root{root}
    {
    }

    void
    traverse(Callback callback)
    {
        if (!callback) {
            throw std::runtime_error{"Invalid callback object"};
        }
        traverse(_root, callback);
    }

private:
    void
    traverse(Node* node, const Callback& callback)
    {
        if (!node) {
            return;
        }

        std::stack<Node*> s1;
        std::stack<Node*> s2;

        s1.push(node);
        while (!s1.empty()) {
            node = s1.top();
            s1.pop();

            if (node->lh) {
                s1.push(node->lh);
            }
            if (node->rh) {
                s1.push(node->rh);
            }

            s2.push(node);
        }

        while (!s2.empty()) {
            node = s2.top();
            callback(node->key, node->value);
            s2.pop();
        }
    }

private:
    Node* _root;
};

} // namespace algorithms
