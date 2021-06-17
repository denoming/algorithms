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
 * @file PrimsMinSpanningTree.hpp
 *
 * @brief Prims min sSpanning tree algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Types.hpp"
#include "EdgeWeightedGraph.hpp"

namespace algorithms {

class PrimsMinSpanningTree {
public:
    explicit PrimsMinSpanningTree(const EdgeWeightedGraph& graph);

    [[nodiscard]] const Edges&
    edges() const;

    [[nodiscard]] double
    weight() const;

private:
    void
    traverse(const EdgeWeightedGraph& graph);

    void
    traverse(const EdgeWeightedGraph& graph, Marks& marks, std::size_t v);

private:
    double _weight;
    Edges _edges;
};

} // namespace algorithms