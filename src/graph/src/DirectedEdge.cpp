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
 * @file DirectedEdge.cpp
 *
 * @brief Directed edge data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "DirectedEdge.hpp"

#include <sstream>
#include <iomanip>

namespace algorithms {

DirectedEdge::DirectedEdge(std::size_t from, std::size_t to, double weight)
    : _from{from}
    , _to{to}
    , _weight{weight}
{
}

std::size_t
DirectedEdge::from() const
{
    return _from;
}

std::size_t
DirectedEdge::to() const
{
    return _to;
}

double
DirectedEdge::weight() const
{
    return _weight;
}

std::string
DirectedEdge::toString() const
{
    std::stringstream ss;
    ss << "{" << _from << ", " << _to << "} "
       << "[" << std::setprecision(5) << _weight << "]";
    return ss.str();
}

bool
DirectedEdge::operator<(const DirectedEdge& other) const
{
    return (_weight < other._weight);
}

bool
DirectedEdge::operator>(const DirectedEdge& other) const
{
    return !(*this < other);
}

bool
DirectedEdge::operator==(const DirectedEdge& other) const
{
    return (_from == other._from && _to == other._to);
}

bool
DirectedEdge::operator!=(const DirectedEdge& other) const
{
    return !(*this == other);
}

} // namespace algorithms