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
 * @file LongestCommonPrefix.hpp
 *
 * @brief Longest common prefix algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <string>

namespace algorithms {

class LongestCommonPrefix {
public:
    static std::string find(const std::string_view& input);

private:
    static std::string_view
    getCommonPrefixLength(const std::string_view& lh, const std::string_view& rh);
};

}