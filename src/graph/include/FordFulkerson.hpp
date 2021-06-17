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
 * @file FordFulkerson.hpp
 *
 * @brief Ford fulkerson algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#pragma once

#include "Types.hpp"
#include "FlowNetwork.hpp"

namespace algorithms {

/**
 * Finds max-flow and min-cut of the flow network
 */
class FordFulkerson {
public:
    FordFulkerson(const FlowNetwork& network, std::size_t s, std::size_t t);

    [[nodiscard]] double
    value() const;

    [[nodiscard]] const Vertices&
    minCut() const;

private:
    void
    traverse(FlowNetwork network, std::size_t s, std::size_t t);

private:
    double _value;
    Vertices _minCut;
};

} // namespace algorithms
