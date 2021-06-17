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
 * @file Routes.cpp
 *
 * @brief Base class for DFS and BFS algorithms implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "Routes.hpp"

#include <limits>

namespace algorithms {

bool
Routes::hasRouteTo(std::size_t vertex) const
{
    return marked[vertex];
}

Vertices
Routes::reachability() const
{
    Vertices output;
    for (std::size_t v{0}; v < marked.size(); ++v) {
        if (marked[v]) {
            output.push_back(v);
        }
    }
    return output;
}

Route
Routes::routeTo(std::size_t vertex) const
{
    if (!hasRouteTo(vertex)) {
        return Route{};
    }

    Route steps;
    steps.push_back(vertex);

    int p = edgeTo[vertex];
    while (p != -1) {
        steps.push_back(p);
        p = edgeTo[p];
    }

    /** Flip over our steps */
    return Route(steps.crbegin(), steps.crend());
}

Routes::Routes(const Graph& graph)
    : marked(graph.verticesCount(), false)
    , edgeTo(graph.verticesCount(), -1)
{
}

} // namespace algorithms
