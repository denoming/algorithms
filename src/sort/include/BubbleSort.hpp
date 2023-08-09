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
 * @file SelectionSort.hpp
 *
 * @brief Selection sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

namespace algorithms {

/**
 * Bubble sort method implementation class.
 *
 * Properties:
 *   - Stable (preserve the ordering of equal elements)
 *   - Worst-case performance: N^2 / 2
 *   - Average performance: N^2 / 2
 *   - Best-case performance: N^2 / 2
 *   - Time complexity: O(n^2)
 *   - Space complexity: O(1)
 */
class BubbleSort {
public:
    template<std::forward_iterator It>
    static void
    sort(It first, It last)
    {
        using T = typename std::iterator_traits<It>::value_type;

        sort(first, last, std::less<T>{});
    }

    template<std::forward_iterator It,
             std::predicate<typename std::iterator_traits<It>::value_type,
                            typename std::iterator_traits<It>::value_type> Compare>
    static void
    sort(It first, It last, Compare compare)
    {
        if (first >= last) {
            return;
        }

        bool hasSwapped{true};
        while (hasSwapped) {
            hasSwapped = false;
            std::forward_iterator auto it1 = first;
            std::forward_iterator auto it2 = std::next(first);
            while (it2 != last) {
                if (compare(*it2, *it1)) {
                    std::iter_swap(it2, it1);
                    hasSwapped = true;
                }
                std::advance(it1, 1);
                std::advance(it2, 1);
            }
        }
    }
};

} // namespace algorithms
