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
 * @file DepthFirstRoutes.hpp
 *
 * @brief Depth first routes algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Routes.hpp"

namespace algorithms {

/**
 * DFS algorithm graph implementation.
 * <p>
 * Properties:
 * <ul>
 * <li>marked all vertices in time proportional to the sum of their degrees
 * <li>each vertex connected to the <em>source</em> is visited once
 * <li>find vertices connected to the <em>source</em> in constant time
 * <li>find a path to the <em>source</em> in time proportional to its length
 * </ul>
 * <p>
 * <b>Not optimal in finding best path between two vertices.</b>
 */
class DepthFirstRoutes final : public Routes {
public:
    DepthFirstRoutes(const Graph& graph, std::size_t source);

    DepthFirstRoutes(const Graph& graph, const Vertices& sources);

private:
    void
    traverse(const Graph& graph, std::size_t source);
};

} // namespace algorithms
