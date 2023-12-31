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
 * @file TopologicalOrderIterator.hpp
 *
 * @brief Topological order iterator algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Digraph.hpp"
#include "DepthFirstOrder.hpp"
#include "EdgeWeightedDigraph.hpp"

#include <memory>

namespace algorithms {

class TopologicalOrderIterator {
public:
    using value_type = Vertices::value_type;
    using difference_type = Vertices::difference_type;
    using pointer = Vertices::pointer;
    using reference = Vertices::reference;
    using iterator_category = std::bidirectional_iterator_tag;

    TopologicalOrderIterator() = default;

    explicit TopologicalOrderIterator(const Digraph& graph);

    explicit TopologicalOrderIterator(const EdgeWeightedDigraph& graph);

    ~TopologicalOrderIterator() = default;

    bool
    operator==(const TopologicalOrderIterator& other) const;

    bool
    operator!=(const TopologicalOrderIterator& other) const;

    value_type
    operator--(int);

    TopologicalOrderIterator&
    operator--();

    value_type
    operator++(int);

    TopologicalOrderIterator&
    operator++();

    value_type
    operator*();

    [[nodiscard]]
    bool hasOrder() const;

    void
    moveToBegin();

    void
    moveToEnd();

private:
    using Iterator = Vertices::const_iterator;

    std::shared_ptr<const Vertices> _vertices;
    Iterator _it;
};

extern TopologicalOrderIterator
begin(const TopologicalOrderIterator& it);

extern TopologicalOrderIterator
end(const TopologicalOrderIterator& it);

} // namespace algorithms
