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
 * @file MultiSourceShortestPaths.hpp
 *
 * @brief Multi source shortest paths algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Types.hpp"
#include "Graph.hpp"

#include <vector>

namespace algorithms {

class MultiSourceShortestPaths {
public:
    using Distances = std::vector<std::size_t>;

    MultiSourceShortestPaths(const Graph& graph, std::initializer_list<std::size_t> ss);

    [[nodiscard]] const Distances&
    distances() const;

private:
    void
    traverse(const Graph& graph, std::initializer_list<std::size_t> ss);

private:
    std::vector<std::size_t> _distances;
};

} // namespace algorithms