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
 * @file AcyclicShortestPaths.hpp
 *
 * @brief Acyclic shortest paths algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "EdgeWeightedDigraph.hpp"

#include <optional>
#include <numeric>

namespace algorithms {

/**
 * Find shortest paths from given vertex.
 *
 * Main goal - compute SPT (shortest path tree) from given vertex
 * in topological order.
 *
 * Provide SPT more quickly than classic algorithms and
 * can be used to obtain longest path also.
 *
 * Note: no cycle must exists but negative weight can be present.
 */
class AcyclicShortestPath {
public:
    using EdgeOrNull = std::optional<DirectedEdge>;

    explicit AcyclicShortestPath(const EdgeWeightedDigraph& graph, std::size_t s, bool shortest = true);

    [[nodiscard]]
    double distanceTo(std::size_t v) const;

    [[nodiscard]]
    DirectedEdges pathTo(std::size_t v) const;

    [[nodiscard]]
    EdgeOrNull edgeTo(std::size_t v) const;

    [[nodiscard]]
    bool hasPathTo(std::size_t v) const;

    static double minDistance();

    static double maxDistance();

private:
    void traverse(const EdgeWeightedDigraph& graph, std::size_t s, bool shortest);

    void relax(const DirectedEdge& edge, bool shortest);

private:
    std::vector<EdgeOrNull> _edgeTo;
    std::vector<double> _distTo;
};

//
// Inlines
//

inline double AcyclicShortestPath::minDistance()
{
    return 0.0;
}

inline double AcyclicShortestPath::maxDistance()
{
    return std::numeric_limits<double>::max();
}

}