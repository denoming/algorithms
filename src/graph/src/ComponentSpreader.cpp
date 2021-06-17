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
 * @file ComponentSpreader.cpp
 *
 * @brief Component spreader algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "ComponentSpreader.hpp"

#include <limits>

namespace algorithms {

ComponentSpreader::ComponentSpreader(const Graph& graph)
    : _count{0}
    , _components(graph.verticesCount(), std::numeric_limits<std::size_t>::max())
{
    traverse(graph);
}

bool
ComponentSpreader::connected(std::size_t v, std::size_t w) const
{
    if (v == w) {
        return true;
    }
    return (_components[v] == _components[w]);
}

std::size_t
ComponentSpreader::count() const
{
    return _count;
}

std::size_t
ComponentSpreader::id(std::size_t v) const
{
    return _components[v];
}

void
ComponentSpreader::traverse(const Graph& graph)
{
    if (graph.empty()) {
        return;
    }

    const std::size_t count = graph.verticesCount();
    Marks marks(count, false);
    for (std::size_t v = 0; v < count; ++v) {
        if (!marks[v]) {
            traverse(graph, v, _count++, marks);
        }
    }
}

void
ComponentSpreader::traverse(const Graph& graph, std::size_t s, std::size_t component, Marks& marks)
{
    _components[s] = component;

    marks[s] = true;
    for (const std::size_t w : graph.adjacency(s)) {
        if (!marks[w]) {
            traverse(graph, w, component, marks);
        }
    }
}

} // namespace algorithms
