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
 * @file BreadthFirstRoutes.hpp
 *
 * @brief Breadth first routes algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Routes.hpp"

namespace algorithms {

/**
 * BFS algorithm graph implementation.
 * <p>
 * Properties:
 * <ul>
 * <li>computes shortest path from source to each fewest vertices
 * <li>each vertex connected to source is visited once
 * <li>finds vertices connected to source in constant time
 * <li>finds a path to s in time proportional to its length
 * </ul>
 * <p>
 * <b>Not optimal in finding best path between two vertices.</b>
 */
class BreadthFirstRoutes final : public Routes {
public:
    BreadthFirstRoutes(const Graph& graph, std::size_t source);

    BreadthFirstRoutes(const Graph& graph, const Vertices& sources);

private:
    void
    traverse(const Graph& graph, std::size_t source);
};

} // namespace algorithms
