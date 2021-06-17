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
 * @file DepthFirstOrder.cpp
 *
 * @brief Depth first order algorithm implementation
 *
 * @author Denys Asauliak
 * Contact: d.asauliak@gmail.com
 */

#include "DepthFirstOrder.hpp"

#include "DirectedCycleFinder.hpp"

#include <functional>
#include <stdexcept>

namespace algorithms {

using Callback = std::function<void(const std::size_t)>;

template<typename T>
void
forEachAdjacency(const T&, std::size_t s, const Callback& callback);

template<>
void
forEachAdjacency<Digraph>(const Digraph& graph, std::size_t s, const Callback& callback)
{
    for (const std::size_t w : graph.adjacency(s)) {
        callback(w);
    }
}

template<>
void
forEachAdjacency<EdgeWeightedDigraph>(const EdgeWeightedDigraph& graph,
                                      std::size_t s,
                                      const Callback& callback)
{
    for (const auto& edge : graph.adjacency(s)) {
        callback(edge.to());
    }
}

DepthFirstOrder::DepthFirstOrder(const Digraph& graph, bool inTopologicalOrder /*= false*/)
    : _pre(graph.verticesCount())
    , _post(graph.verticesCount())
{
    sort(graph, inTopologicalOrder);
}

DepthFirstOrder::DepthFirstOrder(const EdgeWeightedDigraph& graph,
                                 bool inTopologicalOrder /*= false*/)
    : _pre(graph.verticesCount())
    , _post(graph.verticesCount())
{
    sort(graph, inTopologicalOrder);
}

[[nodiscard]] const Vertices&
DepthFirstOrder::pre() const
{
    return _preOrder;
}

[[nodiscard]] std::size_t
DepthFirstOrder::pre(std::size_t v) const
{
    return _pre[v];
}

[[nodiscard]] const Vertices&
DepthFirstOrder::post() const
{
    return _postOrder;
}

[[nodiscard]] std::size_t
DepthFirstOrder::post(std::size_t v) const
{
    return _post[v];
}

[[nodiscard]] Vertices
DepthFirstOrder::reversePost() const
{
    return Vertices(_postOrder.crbegin(), _postOrder.crend());
}

template<typename GraphType>
void
DepthFirstOrder::sort(const GraphType& graph, bool inTopologicalOrder)
{
    if (inTopologicalOrder) {
        DirectedCycleFinder finder{graph};
        if (finder.hasCycle()) {
            throw std::logic_error{"Directed cycle in graph detected"};
        }
    }

    std::size_t preCounter{0}, postCounter{0};
    Marks visitMarks(graph.verticesCount(), false);
    for (std::size_t v = 0; v < graph.verticesCount(); ++v) {
        if (!visitMarks[v]) {
            sort(graph, v, visitMarks, preCounter, postCounter);
        }
    }
}

template<typename GraphType>
void
DepthFirstOrder::sort(const GraphType& graph,
                      std::size_t v,
                      Marks& visitMarks,
                      std::size_t& preCounter,
                      std::size_t& postCounter)
{
    visitMarks[v] = true;

    _pre[v] = preCounter++;
    _preOrder.push_back(v);
    forEachAdjacency(graph, v, [&](const std::size_t w) {
        if (!visitMarks[w]) {
            sort(graph, w, visitMarks, preCounter, postCounter);
        }
    });
    _post[v] = postCounter++;
    _postOrder.push_back(v);
}

} // namespace algorithms
