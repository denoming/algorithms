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
 * @file UndirectedGraph.cpp
 *
 * @brief Undirected graph data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "UndirectedGraph.hpp"

namespace algorithms {

UndirectedGraph::UndirectedGraph(std::size_t numberOfVertices)
    : Graph{numberOfVertices}
{
}

void
UndirectedGraph::connect(std::size_t v1, std::size_t v2)
{
    edges++;
    forest[v1].push_front(v2);
    forest[v2].push_front(v1);
}

std::size_t
UndirectedGraph::countOfSelfLoop(const Graph& graph)
{
    std::size_t count{0};
    for (std::size_t v = 0; v < graph.verticesCount(); ++v) {
        for (std::size_t w : graph.adjacency(v)) {
            if (v == w) {
                count++;
            }
        }
    }
    return count / 2;
}

double
UndirectedGraph::averageDegree(const Graph& graph)
{
    return 2.0 * graph.edgesCount() / graph.verticesCount();
}

} // namespace algorithms
