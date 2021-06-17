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
 * @file EdgeWeightedGraph.cpp
 *
 * @brief Edge weighted graph data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "EdgeWeightedGraph.hpp"

namespace algorithms {

EdgeWeightedGraph::EdgeWeightedGraph()
    : _edges{0}
{
}

EdgeWeightedGraph::EdgeWeightedGraph(std::size_t numberOfVertices)
    : _edges{0}
    , _forest{numberOfVertices}
{
}

void
EdgeWeightedGraph::add(const Edge& edge)
{
    _edges++;

    std::size_t v = edge.either();
    std::size_t w = edge.other(v);

    _forest[v].push_front(edge);
    _forest[w].push_front(edge);
}

const EdgeWeightedGraph::EdgesList&
EdgeWeightedGraph::adjacency(std::size_t v) const
{
    return _forest[v];
}

Edges
EdgeWeightedGraph::edges() const
{
    Edges edges;
    for (const auto& edgeList : _forest) {
        for (const auto& edge : edgeList) {
            edges.push_back(edge);
        }
    }
    return edges;
}

std::size_t
EdgeWeightedGraph::verticesCount() const
{
    return _forest.size();
}

std::size_t
EdgeWeightedGraph::edgesCount() const
{
    return _edges;
}

void
EdgeWeightedGraph::reset(std::size_t numberOfVertices)
{
    _edges = 0;
    Forest(numberOfVertices).swap(_forest);
}

bool
EdgeWeightedGraph::empty() const
{
    return _forest.empty();
}

} // namespace algorithms
