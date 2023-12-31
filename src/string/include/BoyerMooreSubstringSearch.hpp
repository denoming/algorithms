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
 * @file BoyerMooreSubstringSearch.hpp
 *
 * @brief BoyerMoore substring search algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <array>
#include <string_view>

namespace algorithms {

/**
 * The Boyer-Moore substring search algorithm implementation.
 */
template<typename Ch = char>
class BoyerMooreSubstringSearch {
public:
    static constexpr int NotFound = -1;

public:
    /** The number of possible character values */
    static constexpr std::size_t R = std::numeric_limits<Ch>::max() + 1;

    static int search(std::basic_string_view<Ch> text, std::basic_string_view<Ch> pattern)
    {
        const int N = text.size();
        const int M = pattern.size();

        std::array<int, R> offsets;
        for (std::size_t r{0}; r < R; ++r) {
            offsets[r] = -1;
        }
        for (std::size_t i{0}; i < M; ++i) {
            offsets[pattern[i]] = i;
        }

        for (int i{0}, skip{0}; i < N - M; i += skip, skip = 0) {
            for (int j{M - 1}; j >= 0; --j) {
                if (pattern[j] != text[i + j]) {
                    skip = std::max(1, j - offsets[text[i + j]]);
                    break;
                }
            }
            if (skip == 0) {
                return i;
            }
        }

        return NotFound;
    }
};

}