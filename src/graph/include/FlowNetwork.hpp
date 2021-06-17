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
 * @file FlowNetwork.hpp
 *
 * @brief Flow network data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "FlowEdge.hpp"

#include <forward_list>
#include <vector>

namespace algorithms {

class FlowNetwork {
public:
    using EdgesList = std::forward_list<FlowEdge>;
    using Forest = std::vector<EdgesList>;

    FlowNetwork() = default;

    explicit FlowNetwork(std::size_t numberOfVertices);

    void
    add(const FlowEdge& edge);

    [[nodiscard]] const EdgesList&
    adjacency(std::size_t v) const;

    [[nodiscard]] EdgesList&
    adjacency(std::size_t v);

    [[nodiscard]] std::size_t
    verticesCount() const;

    void
    reset(std::size_t numberOfVertices);

    [[nodiscard]] bool
    empty() const;

private:
    Forest _forest;
};

} // namespace algorithms
