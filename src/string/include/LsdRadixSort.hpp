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
 * @file LsdRadixSort.hpp
 *
 * @brief LSD radix sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Types.hpp"

namespace algorithms {

/**
 * Least-significant-digit-first string sort by key-indexed counting
 */
class LsdRadixSort {
public:
    static void
    sort(StringViews& views, std::size_t maxLength);

private:
    static void
    sort(StringViews& views, std::size_t maxLength, StringViews& aux);
};

} // namespace algorithms