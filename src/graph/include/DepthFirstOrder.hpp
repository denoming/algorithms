#pragma once

#include "Types.hpp"
#include "Digraph.hpp"

namespace algorithms {

/**
 * Depth first order sorter implementation
 */
class DepthFirstOrder {
public:
    explicit DepthFirstOrder(const Digraph& graph, bool inTopologicalOrder = false);

    [[nodiscard]] const Vertices&
    reversePost() const;

private:
    void
    sort(const Digraph& graph, bool inTopologicalOrder);

    void
    sort(const Digraph& graph, std::size_t s, Marks& marks);

private:
    Vertices _reversePost;
};

} // namespace algorithms
