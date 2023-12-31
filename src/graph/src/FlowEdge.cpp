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
 * @file FlowEdge.cpp
 *
 * @brief Flow edge graph data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "FlowEdge.hpp"

#include <stdexcept>

namespace algorithms {

FlowEdge::FlowEdge(std::size_t v, std::size_t w, double capacity)
    : _v{v}
    , _w{w}
    , _capacity{capacity}
    , _flow{0.0}
{
}

std::size_t
FlowEdge::from() const
{
    return _v;
}

std::size_t
FlowEdge::to() const
{
    return _w;
}

std::size_t
FlowEdge::other(std::size_t v) const
{
    if (v == _v) {
        return _w;
    }
    if (v == _w) {
        return _v;
    }
    throw std::logic_error{"Invalid input argument"};
}

double
FlowEdge::capacity() const
{
    return _capacity;
}

double
FlowEdge::flow() const
{
    return _flow;
}

double
FlowEdge::residualCapacityTo(std::size_t v) const
{
    if (v == _w) { // Forward edge
        return _capacity - _flow;
    }
    if (v == _v) { // Backward edge
        return _flow;
    }
    throw std::logic_error{"Invalid input argument"};
}

void
FlowEdge::addResidualFlowTo(std::size_t v, double delta)
{
    if (v == _w) { // Forward Edge
        _flow += delta;
        return;
    }
    if (v == _v) { // Backward edge
        _flow -= delta;
        return;
    }
    throw std::logic_error{"Invalid input argument"};
}

} // namespace algorithms
