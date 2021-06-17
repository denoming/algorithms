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
 * @file MultiSourceShortestPaths.cpp
 *
 * @brief Multi source shortest paths algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "MultiSourceShortestPaths.hpp"

#include <queue>

namespace algorithms {

MultiSourceShortestPaths::MultiSourceShortestPaths(const Graph& graph,
                                                   std::initializer_list<std::size_t> ss)
    : _distances(graph.verticesCount(), 0)
{
    traverse(graph, ss);
}

void
MultiSourceShortestPaths::traverse(const Graph& graph, std::initializer_list<std::size_t> ss)
{
    Marks marks(graph.verticesCount(), false);

    std::queue<std::size_t> vertices;
    for (const std::size_t s : ss) {
        marks[s] = true;
        vertices.push(s);
    }

    while (!vertices.empty()) {
        const std::size_t s = vertices.front();
        vertices.pop();

        for (const std::size_t v : graph.adjacency(s)) {
            if (!marks[v]) {
                marks[v] = true;
                _distances[v] = _distances[s] + 1;
                vertices.push(v);
            }
        }
    }
}
const MultiSourceShortestPaths::Distances&
MultiSourceShortestPaths::distances() const
{
    return _distances;
}

} // namespace algorithms