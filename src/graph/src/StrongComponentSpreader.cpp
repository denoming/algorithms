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
 * @file StrongComponentSpreader.cpp
 *
 * @brief Strong component spreader algorithms implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "StrongComponentSpreader.hpp"

#include "DepthFirstOrder.hpp"

#include <limits>

namespace algorithms {

StrongComponentSpreader::StrongComponentSpreader(const Digraph& graph)
    : _count{0}
    , _components(graph.verticesCount(), std::numeric_limits<std::size_t>::max())
{
    traverse(graph);
}

bool
StrongComponentSpreader::connected(std::size_t v, std::size_t w) const
{
    if (v == w) {
        return true;
    }
    return (_components[v] == _components[w]);
}

std::size_t
StrongComponentSpreader::count() const
{
    return _count;
}

std::size_t
StrongComponentSpreader::id(std::size_t v) const
{
    return _components[v];
}

void
StrongComponentSpreader::traverse(const Digraph& graph)
{
    if (graph.empty()) {
        return;
    }

    Marks marks(graph.verticesCount(), false);

    DepthFirstOrder order{graph.reverse()};
    const auto vertices = order.reversePost();
    for (const std::size_t v : vertices) {
        if (!marks[v]) {
            traverse(graph, v, _count++, marks);
        }
    }
}

void
StrongComponentSpreader::traverse(const Digraph& graph,
                                  std::size_t s,
                                  std::size_t component,
                                  Marks& marks)
{
    _components[s] = component;

    marks[s] = true;
    for (const std::size_t v : graph.adjacency(s)) {
        if (!marks[v]) {
            traverse(graph, v, component, marks);
        }
    }
}

} // namespace algorithms
