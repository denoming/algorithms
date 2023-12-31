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
 * @file FlowEdge.hpp
 *
 * @brief Flow edge graph data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <typeindex>

namespace algorithms {

class FlowEdge {
public:
    FlowEdge(std::size_t v, std::size_t w, double capacity);

    [[nodiscard]]
    std::size_t from() const;

    [[nodiscard]]
    std::size_t to() const;

    [[nodiscard]]
    std::size_t other(std::size_t v) const;

    [[nodiscard]]
    double capacity() const;

    [[nodiscard]]
    double flow() const;

    [[nodiscard]]
    double residualCapacityTo(std::size_t v) const;

    void addResidualFlowTo(std::size_t v, double delta);

private:
    std::size_t _v;
    std::size_t _w;
    double _capacity;
    double _flow;
};

}
