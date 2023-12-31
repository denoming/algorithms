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
 * @file Rect.cpp
 *
 * @brief Rect data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "Rect.hpp"

#include "LineSegment.hpp"

namespace algorithms {

Rect::Rect(const Point& topLeft, const Point& bottomRight)
    : p1{topLeft}
    , p4{bottomRight}
{
    p2 = Point{p1.x, p4.y};
    p3 = Point{p4.x, p1.y};
}

Rect::Rect(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : p1{p1}
    , p2{p2}
    , p3{p3}
    , p4{p4}
{
}

bool
Rect::operator==(const Rect& other) const
{
    if (this != &other) {
        return p1 == other.p1 && p2 == other.p2 && p3 == other.p3 && p4 == other.p4;
    }
    return true;
}

bool
Rect::operator!=(const Rect& other) const
{
    return !(*this == other);
}

bool
Rect::isOrthogonal() const
{
    const LineSegment s1{p1, p2};
    const LineSegment s2{p1, p3};
    return s1.isHorizontal() && s2.isVertical();
}

} // namespace algorithms
