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
 * @file GrahamScan.hpp
 *
 * @brief Graham scan algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Points.hpp"

namespace algorithms {

class GrahamScan {
public:
    GrahamScan() = default;

    explicit GrahamScan(const Points& points);

    void
    scan(Points points);

    [[nodiscard]] const Points&
    hull() const;

private:
    Points _hull;
};

//
// Inlines
//

inline const Points&
GrahamScan::hull() const
{
    return _hull;
}

} // namespace algorithms