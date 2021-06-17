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
 * @file DepthFirstRoutes.cpp
 *
 * @brief Depth first routes algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "DepthFirstRoutes.hpp"

namespace algorithms {

DepthFirstRoutes::DepthFirstRoutes(const Graph& graph, std::size_t source)
    : Routes{graph}
{
    traverse(graph, source);
}

DepthFirstRoutes::DepthFirstRoutes(const Graph& graph, const Vertices& sources)
    : Routes{graph}
{
    for (std::size_t v : sources) {
        traverse(graph, v);
    }
}

void
DepthFirstRoutes::traverse(const Graph& graph, std::size_t source)
{
    marked[source] = true;
    for (std::size_t v : graph.adjacency(source)) {
        if (!marked[v]) {
            edgeTo[v] = source;
            /* Used recursion to go deeply of graph */
            traverse(graph, v);
        }
    }
}

} // namespace algorithms
