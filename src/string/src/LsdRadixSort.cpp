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
 * @file LsdRadixSort.cpp
 *
 * @brief LSD radix sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "LsdRadixSort.hpp"

#include <numeric>

static const auto R = std::numeric_limits<unsigned char>::max();

namespace algorithms {

void
LsdRadixSort::sort(StringViews& views, std::size_t maxLength)
{
    static thread_local StringViews aux(views.size());
    sort(views, maxLength, aux);
}

void
LsdRadixSort::sort(StringViews& views, std::size_t maxLength, StringViews& aux)
{
    for (int d = static_cast<int>(maxLength) - 1; d >= 0; --d) {
        /* Count frequencies of each letter using d'n char as index */
        std::size_t count[R + 1] = {};
        for (const auto& view : views) {
            count[view[d] + 1]++;
        }
        /* Compute frequency cumulates which specify destinations */
        for (std::size_t r = 0; r < R; ++r) {
            count[r + 1] += count[r];
        }
        /* Put each string to the destination inside auxiliary array */
        for (const auto& view : views) {
            aux[count[view[d]]++] = view;
        }
        /* Copy back to the input array */
        for (std::size_t n = 0; n < views.size(); ++n) {
            views[n] = aux[n];
        }
    }
}

} // namespace algorithms