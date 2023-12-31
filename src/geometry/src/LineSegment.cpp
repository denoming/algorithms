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
 * @file LineSegment.cpp
 *
 * @brief Line segment data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "LineSegment.hpp"

namespace algorithms {

LineSegment::LineSegment(const Point& p1, const Point& p2)
    : p1{p1}
    , p2{p2}
{
}

bool
LineSegment::isVertical() const
{
    return p1.equalByX(p2);
}

bool
LineSegment::isHorizontal() const
{
    return p1.equalByY(p2);
}

bool
LineSegment::isOrthogonal() const
{
    return isHorizontal() || isVertical();
}

bool
LineSegment::operator<(const LineSegment& other) const
{
    if (p1.y < other.p1.y || p2.y < other.p2.y) {
        return true;
    }
    if (p1.y > other.p1.y || p2.y > other.p2.y) {
        return false;
    }
    if (p1.x < other.p1.x || p2.x < other.p2.x) {
        return true;
    }
    if (p1.x > other.p1.x || p2.x > other.p2.x) {
        return false;
    }
    return false;
}

} // namespace algorithms
