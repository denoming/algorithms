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
 * @file DepthPreOrderTraverse.hpp
 *
 * @brief Depth pre-order traverse algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <functional>

namespace algorithms {

/**
 * Depth pre-order traversal of tree using recursion.
 *
 * Order: (Root, Left, Right)
 *  - Visit the root
 *  - Traverse the left subtree
 *  - Traverse the right subtree
 *
 * Used to create a copy of the tree (in the same order as was inserted).
 */
template<typename Node>
class DepthPreOrderTraverser {
public:
    using Callback = std::function<void(const typename Node::KeyType&, typename Node::ValueType&)>;

    explicit DepthPreOrderTraverser(Node* root)
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

        callback(node->key, node->value);
        traverse(node->lh, callback);
        traverse(node->rh, callback);
    }

private:
    Node* _root;
};

} // namespace algorithms
