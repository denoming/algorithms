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
 * @file Edge.hpp
 *
 * @brief Edge data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <vector>
#include <string>

namespace algorithms {

/**
 * The weighted edge representation
 */
class Edge {
public:
    Edge(std::size_t v, std::size_t w, double weight);

    [[nodiscard]] std::size_t
    either() const;

    [[nodiscard]] std::size_t
    other(std::size_t v) const;

    [[nodiscard]] double
    weight() const;

    [[nodiscard]] std::string
    toString() const;

    bool
    operator<(const Edge& other) const;

    bool
    operator>(const Edge& other) const;

    bool
    operator==(const Edge& other) const;

    bool
    operator!=(const Edge& other) const;

private:
    std::size_t _v;
    std::size_t _w;
    double _weight;
};

/** The list of weighted edges */
using Edges = std::vector<Edge>;

} // namespace algorithms
