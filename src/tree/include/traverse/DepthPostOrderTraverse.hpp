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
 * @file DepthPostOrderTraverse.hpp
 *
 * @brief Depth post-order traverse algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <functional>

namespace algorithms {

/**
 * Depth post-order traversal of tree using recursion.
 *
 * Order: (Root, Left, Right)
 *  - Traverse the left subtree
 *  - Traverse the right subtree
 *  - Visit the root
 *
 * Used to delete the tree. Also useful to get the postfix expression.
 */
template<typename Node>
class DepthPostOrderTraverser {
public:
    using Callback = std::function<void(const typename Node::KeyType&, typename Node::ValueType&)>;

    explicit DepthPostOrderTraverser(Node* root)
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

        traverse(node->lh, callback);
        traverse(node->rh, callback);
        callback(node->key, node->value);
    }

private:
    Node* _root;
};

} // namespace algorithms
