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
 * @file KruskalMinSpanningTree.hpp
 *
 * @brief Kruskal min spanning tree algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "EdgeWeightedGraph.hpp"

namespace algorithms {

/**
 * Kruskal greedy algorithms implementation
 */
class KruskalMinSpanningTree {
public:
    using Edges = std::vector<Edge>;

    explicit KruskalMinSpanningTree(const EdgeWeightedGraph& graph);

    [[nodiscard]] const Edges&
    edges() const;

    [[nodiscard]] double
    weight() const;

private:
    void
    traverse(const EdgeWeightedGraph& graph);

private:
    double _weight;
    Edges _edges;
};

} // namespace algorithms
