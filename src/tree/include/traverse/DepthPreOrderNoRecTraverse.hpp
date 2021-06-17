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
 * @file DepthPreOrderNoRecTraverse.hpp
 *
 * @brief Depth pre-order traverse algorithm implementation (without recursion)
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <stack>
#include <functional>

namespace algorithms {

/**
 * Depth pre-order traversal of tree without recursion.
 *
 * See full description in @file DepthPostOrderTraverse.hpp
 */
template<typename Node>
class DepthPreOrderNoRecTraverser {
public:
    using Callback = std::function<void(const typename Node::KeyType&, typename Node::ValueType&)>;

    explicit DepthPreOrderNoRecTraverser(Node* root)
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
        std::stack<Node*> nodes;
        while (node || !nodes.empty()) {
            while (node) {
                callback(node->key, node->value);
                nodes.push(node);
                node = node->lh;
            }

            node = nodes.top();
            nodes.pop();
            node = node->rh;
        }
    }

private:
    Node* _root;
};

} // namespace algorithms
