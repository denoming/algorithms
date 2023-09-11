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
 * @file HeapSort.hpp
 *
 * @brief Heap sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <functional>
#include <iterator>
#include <utility>
#include <concepts>

namespace algorithms {

/**
 * Heap sort method implementation class.
 *
 * Heap-ordered binary  tree has mandatory condition: parent's key is not smaller
 * than children's key.
 *
 * Properties:
 *   - Not stable
 *   - Inplace
 *   - Worst-case performance: 2N x lgN / 2
 *   - Average performance: 2N x lgN / 2
 *   - Best-case performance: N x lgN
 *   - Time complexity: O(N log N)
 *   - Space complexity: O(1)
 *
 * Remark: No linear extra space and no quadratic time in worst case,
 *         but makes poor use of cache memory (bad cache locality).
 *         Heapsort swaps elements based on location in heaps, which
 *         can cause many read operations in a seemingly random order,
 *         causing many cache misses.
 */
class HeapSort {
public:
    template<std::random_access_iterator It>
    static void
    sort(It first, It last)
    {
        using T = typename std::iterator_traits<It>::value_type;

        sort(first, last, std::less<T>{});
    }

    template<std::random_access_iterator It,
             std::predicate<typename std::iterator_traits<It>::value_type,
                            typename std::iterator_traits<It>::value_type> Compare>
    static void
    sort(It first, It last, Compare compare)
    {
        if (first >= last) {
            return;
        }

        //    Bottom-up heapify unordered array
        // (at the top we will have the max element)
        std::size_t size = std::distance(first, last);
        for (std::size_t k = size / 2 /* Optimization: Start from the middle */; k >= 1; --k) {
            sink(first, k, size, compare);
        }

        while (size > 1) {
            /* Swap max element with the last element */
            std::swap(first[0], first[size - 1]);
            size--; // Decrease heap size by 1
            /* Heapify A[0, ..., heap.size - 1] again (dispose last element to the proper place) */
            sink(first, 1, size, compare);
        }
    }

private:
    /**
     *
     * Parent node at k is at k/2
     * Children of node at k are at 2k and 2k+1
     *
     *   i  0 1 2 3 4 5 6 7 8 9
     * a[i] - 2 1 0 3 7 5 6 5 8
     *        2 + -
     *          1 0 + + - -
     *              3 7 5 6 + +
     *                      8 9
     *
     */
    template<typename It, typename Compare>
    static void
    sink(It input, std::size_t k, std::size_t size, Compare compare)
    {
        while (2 * k <= size) {
            std::size_t j = 2 * k;
            // Examine children key (find out the max children)
            if (j < size && compare(input[j - 1], input[j])) {
                j++;
            }
            // Examine parent and max children
            if (compare(input[k - 1], input[j - 1])) {
                std::swap(input[k - 1], input[j - 1]);
                k = j;
            } else {
                break;
            }
        }
    }
};

} // namespace algorithms
