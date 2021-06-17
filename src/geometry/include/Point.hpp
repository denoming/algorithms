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
 * @file Point.hpp
 *
 * @brief Point data type implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

namespace algorithms {

struct Point {
    Point();

    Point(float x, float y);

    bool
    operator==(const Point& other) const;

    bool
    operator!=(const Point& other) const;

    [[nodiscard]] bool
    equalByX(const Point& other) const;

    [[nodiscard]] bool
    equalByY(const Point& other) const;

    float x;
    float y;
};

} // namespace algorithms
