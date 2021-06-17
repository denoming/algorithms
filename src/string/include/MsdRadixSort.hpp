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
 * @file MsdRadixSort.hpp
 *
 * @brief MSD radix sort algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Types.hpp"

namespace algorithms {

class MsdRadixSort {
public:
    static void
    sort(StringViews& views);

private:
    static void
    sort(StringViews& views, StringViews& aux, long lo, long hi, std::size_t d);

    static void
    sort(StringViews& views, long lo, long hi);

    static unsigned char
    charAt(const std::string_view& view, std::size_t d);
};

} // namespace algorithms