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
 * @file RegExpMatcher.hpp
 *
 * @brief RegExp matcher algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include <string>
#include <string_view>

#include "Digraph.hpp"

namespace algorithms {

/**
 * Regular expression match implementation.
 */
class RegExpMatcher {
public:
    explicit RegExpMatcher(std::string_view pattern);

    [[nodiscard]] bool
    match(std::string_view text) const;

private:
    void
    buildEpsilonTransitions();

private:
    const std::string _pattern;
    Digraph _transitions;
};

} // namespace algorithms