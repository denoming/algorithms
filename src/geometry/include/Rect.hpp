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
 * @file Rect.hpp
 *
 * @brief Rect data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Point.hpp"

namespace algorithms {

struct Rect {
    Rect(const Point& topLeft, const Point& bottomRight);

    Rect(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    bool
    operator==(const Rect& other) const;
    bool
    operator!=(const Rect& other) const;

    bool
    isOrthogonal() const;

    Point p1; //!> Top Left
    Point p2; //!> Bottom Left
    Point p3; //!> Top Right
    Point p4; //!> Bottom Right
};

} // namespace algorithms
