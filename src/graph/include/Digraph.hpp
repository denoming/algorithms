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
 * @file Digraph.hpp
 *
 * @brief Digraph data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Types.hpp"
#include "Graph.hpp"

namespace algorithms {

/**
 * The class of directed graph.
 */
class Digraph final : public Graph {
public:
    Digraph() = default;

    explicit Digraph(std::size_t numberOfVertices);

    void
    connect(std::size_t v1, std::size_t v2) override;

    [[nodiscard]] Digraph
    reverse() const;

public:
    /**
     * Counts the number of loops in graph.
     * @param graph The given loop.
     * @return The number of loops.
     */
    [[nodiscard]] static std::size_t
    countOfSelfLoop(const Graph& graph);

    /**
     * Calculates the average number of degree in provided graph.
     * @param graph The given graph.
     * @return The average degree.
     */
    [[nodiscard]] static double
    averageDegree(const Graph& graph);
};

} // namespace algorithms
