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
 * @file DirectedEdge.hpp
 *
 * @brief Directed edge data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <vector>
#include <string>

namespace algorithms {

/**
 * The directed weighted edge representation
 */
class DirectedEdge {
public:
    DirectedEdge(std::size_t from, std::size_t to, double weight);

    [[nodiscard]] std::size_t
    from() const;

    [[nodiscard]] std::size_t
    to() const;

    [[nodiscard]] double
    weight() const;

    [[nodiscard]] std::string
    toString() const;

    bool
    operator<(const DirectedEdge& other) const;

    bool
    operator>(const DirectedEdge& other) const;

    bool
    operator==(const DirectedEdge& other) const;

    bool
    operator!=(const DirectedEdge& other) const;

private:
    std::size_t _from;
    std::size_t _to;
    double _weight;
};

/** The list of directed weighted edges */
using DirectedEdges = std::vector<DirectedEdge>;

} // namespace algorithms