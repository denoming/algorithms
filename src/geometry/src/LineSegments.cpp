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
 * @file LineSegments.cpp
 *
 * @brief Line segment data type support methods implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "LineSegments.hpp"

#include "Points.hpp"

namespace algorithms {

bool
intersects(const LineSegment& s1, const LineSegment& s2)
{
    static auto onSegment = [](const Point& p, const Point& q, const Point& r) {
        const bool byX = (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x));
        const bool byY = (q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
        return byX && byY;
    };

    int o1 = getOrientation(s1.p1, s1.p2, s2.p1);
    int o2 = getOrientation(s1.p1, s1.p2, s2.p2);
    int o3 = getOrientation(s2.p1, s2.p2, s1.p1);
    int o4 = getOrientation(s2.p1, s2.p2, s1.p2);

    // General case (base on orientation of point combinations)
    if (o1 != o2 && o3 != o4) {
        return true;
    }

    // Special case (base on collinear state and the presence in these segments)
    if (o1 == 0 && onSegment(s1.p1, s2.p1, s1.p2)) {
        return true;
    }
    if (o2 == 0 && onSegment(s1.p1, s2.p2, s1.p2)) {
        return true;
    }
    if (o3 == 0 && onSegment(s2.p1, s1.p1, s2.p2)) {
        return true;
    }
    if (o4 == 0 && onSegment(s2.p1, s1.p2, s2.p2)) {
        return true;
    }

    return false;
}

} // namespace algorithms
