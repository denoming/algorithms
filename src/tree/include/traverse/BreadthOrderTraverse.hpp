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
 * @file BreadthOrderTraverse.hpp
 *
 * @brief Breadth order traverse algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <queue>
#include <functional>

namespace algorithms {

/**
 * Breadth order traversal of tree.
 *
 *
 */
template<typename Node>
class BreadthOrderTraverser {
public:
    using Callback = std::function<void(const typename Node::KeyType&, typename Node::ValueType&)>;

    explicit BreadthOrderTraverser(Node* root)
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

        std::queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            auto e = q.front();
            callback(e->key, e->value);
            if (e->lh) {
                q.push(e->lh);
            }
            if (e->rh) {
                q.push(e->rh);
            }
            q.pop();
        }
    }

private:
    Node* _root;
};

} // namespace algorithms
