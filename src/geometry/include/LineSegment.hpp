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
 * @file LineSegment.hpp
 *
 * @brief Line segment data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Point.hpp"

namespace algorithms {

/**
 * The line segment.
 */
struct LineSegment {
    LineSegment() = default;

    LineSegment(const Point& p1, const Point& p2);

    [[nodiscard]] bool
    isVertical() const;

    [[nodiscard]] bool
    isHorizontal() const;

    [[nodiscard]] bool
    isOrthogonal() const;

    bool
    operator<(const LineSegment& other) const;

    Point p1;
    Point p2;
};

} // namespace algorithms
