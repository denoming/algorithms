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
 * @file MsdRadixSort.cpp
 *
 * @brief MSD radix sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "MsdRadixSort.hpp"

#include <numeric>

namespace algorithms {

void
MsdRadixSort::sort(StringViews& views)
{
    StringViews aux(views.size());
    sort(views, aux, 0, static_cast<long>(views.size()) - 1, 0);
}

void
MsdRadixSort::sort(StringViews& views, StringViews& aux, long lo, long hi, std::size_t d)
{
    static const int R = std::numeric_limits<unsigned char>::max();
    static const int SmallSubArrayThreshold = 3;

    if (hi <= lo) {
        return;
    }

    if (hi - lo <= SmallSubArrayThreshold) {
        /* Sort small sub-arrays by insertion algorithm (reduce extra space consumption) */
        sort(views, lo, hi);
        return;
    }

    long count[R + 2 /* Reserve place for special value */] = {};
    for (long i = lo; i <= hi; ++i) {
        count[charAt(views[i], d) + 2]++;
    }
    for (std::size_t r = 0; r < R + 1; ++r) {
        count[r + 1] += count[r];
    }
    for (long i = lo; i <= hi; ++i) {
        aux[count[charAt(views[i], d) + 1 /* Place short string on top */]++] = views[i];
    }
    for (long i = lo; i <= hi; ++i) {
        views[i] = aux[i - lo];
    }

    /* Sort recursively of sub-arrays */
    for (std::size_t r = 0; r < R; ++r) {
        sort(views, aux, lo + count[r], lo + count[r + 1] - 1, d + 1);
    }
}

void
MsdRadixSort::sort(StringViews& views, long lo, long hi)
{
    for (long i = lo + 1; i <= hi; ++i) {
        for (long j = i; j > lo; --j) {
            if (std::lexicographical_compare(views[j].cbegin(),
                                             views[j].cend(),
                                             views[j - 1].cbegin(),
                                             views[j - 1].cend())) {
                views[j].swap(views[j - 1]);
            }
        }
    }
}

unsigned char
MsdRadixSort::charAt(const std::string_view& view, std::size_t d)
{
    return (d < view.size()) ? view[d] : -1 /* Return special value for shorter string */;
}

} // namespace algorithms