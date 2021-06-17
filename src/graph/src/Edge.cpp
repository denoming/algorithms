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
 * @file Edge.cpp
 *
 * @brief Edge data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "Edge.hpp"

#include <sstream>
#include <iomanip>

namespace algorithms {

Edge::Edge(std::size_t v, std::size_t w, double weight)
    : _v{v}
    , _w{w}
    , _weight{weight}
{
}

std::size_t
Edge::either() const
{
    return _v;
}

std::size_t
Edge::other(std::size_t v) const
{
    return (v == _v) ? _w : _v;
}

double
Edge::weight() const
{
    return _weight;
}

std::string
Edge::toString() const
{
    std::stringstream ss;
    ss << "{" << _v << ", " << _w << "} "
       << "[" << std::setprecision(5) << _weight << "]";
    return ss.str();
}

bool
Edge::operator<(const Edge& other) const
{
    return (_weight < other._weight);
}

bool
Edge::operator>(const Edge& other) const
{
    return !(*this < other);
}

bool
Edge::operator==(const Edge& other) const
{
    return (_v == other._v && _w == other._w);
}

bool
Edge::operator!=(const Edge& other) const
{
    return !(*this == other);
}

} // namespace algorithms
