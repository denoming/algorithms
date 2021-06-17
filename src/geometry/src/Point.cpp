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
 * @file Point.cpp
 *
 * @brief Point data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "Point.hpp"

#include <limits>
#include <cmath>

namespace algorithms {

Point::Point()
    : x{0.0}
    , y{0.0}
{
}

Point::Point(float x, float y)
    : x{x}
    , y{y}
{
}

bool
Point::operator==(const Point& other) const
{
    return equalByX(other) && equalByX(other);
}

bool
Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

bool
Point::equalByX(const Point& other) const
{
    return std::abs(x - other.x) < std::numeric_limits<float>::epsilon();
}

bool
Point::equalByY(const Point& other) const
{
    return std::abs(y - other.y) < std::numeric_limits<float>::epsilon();
}

} // namespace algorithms
