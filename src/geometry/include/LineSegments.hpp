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
 * @file LineSegments.hpp
 *
 * @brief Line segment data type support methods implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "LineSegment.hpp"

#include <vector>

namespace algorithms {

/**
 * The set of line segments.
 */
using LineSegments = std::vector<LineSegment>;

/**
 * Checks if one line segment intersects another.
 *
 * @param s1 - the segment one
 * @param s2 - the segment two
 *
 * @return \c true if s1 intersects s2, \c false otherwise
 */
bool
intersects(const LineSegment& s1, const LineSegment& s2);

} // namespace algorithms
