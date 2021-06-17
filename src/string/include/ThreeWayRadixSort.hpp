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
 * @file ThreeWayRadixSort.hpp
 *
 * @brief Three-way radix sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Types.hpp"

namespace algorithms {

/**
 * Radix sort using three way partitioning.
 *
 * Properties:
 *   - Not stable
 *   - Inplace
 *   - Worst-case performance: 1.39 W N lgN
 *   - Average performance: 1.39 N lgN
 *   - Extra Space: logN + W
 */
class ThreeWayRadixSort {
public:
    static void
    sort(StringViews& views);

private:
    static void
    sort(StringViews& views, int lo, int hi, std::size_t d);
};

} // namespace algorithms