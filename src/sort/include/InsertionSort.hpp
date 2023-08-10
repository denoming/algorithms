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
 * @file InsertionSort.hpp
 *
 * @brief Insertion sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <iterator>
#include <concepts>
#include <algorithm>
#include <functional>

namespace algorithms {

/**
 * Insertion sort method implementation class.
 *
 * Properties:
 *   - Stable
 *   - Inplace
 *   - Worst-case performance: N^2 / 2 (sorted list in reverse order)
 *   - Average performance: N^2 / 4
 *   - Best-case performance: N
*    - Time complexity: O(n^2)
*    - Space complexity: O(1)
 *
 * Remark: Use for small N or for partially ordered elements.
 */
class InsertionSort {
public:
    template<std::bidirectional_iterator It>
    static void
    sort(It first, It last)
    {
        using T = typename std::iterator_traits<It>::value_type;

        sort(first, last, std::less<T>{});
    }

    template<std::bidirectional_iterator It,
             std::predicate<typename std::iterator_traits<It>::value_type,
                            typename std::iterator_traits<It>::value_type> Compare>
    static void
    sort(It first, It last, Compare compare)
    {
        if (first >= last) {
            return;
        }

        for (auto it = std::next(first); it != last; ++it) {
            for (auto curr = it; curr != first;) {
                auto prev = std::prev(curr);
                if (compare(*curr, *prev)) {
                    std::iter_swap(curr, prev);
                    curr = prev;
                } else {
                    /*  */
                    break;
                }
            }
        }
    }
};

} // namespace algorithms
