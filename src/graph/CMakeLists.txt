set(TARGET Graph-Library)

add_library(${TARGET})
add_library(Graph::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PRIVATE include/Graph.hpp
            include/Digraph.hpp
            include/UndirectedGraph.hpp
            include/Routes.hpp
            include/DepthFirstRoutes.hpp
            include/BreadthFirstRoutes.hpp
            include/ComponentSpreader.hpp
            include/StrongComponentSpreader.hpp
            include/MultiSourceShortestPaths.hpp
            include/DepthFirstOrder.hpp
            include/Edge.hpp
            include/EdgeWeightedGraph.hpp
            include/KruskalMinSpanningTree.hpp
            include/PrimsMinSpanningTree.hpp
            include/DirectedEdge.hpp
            include/EdgeWeightedDigraph.hpp
            include/DijkstraShortestPaths.hpp
            include/DirectedCycleFinder.hpp
            include/TopologicalOrderIterator.hpp
            include/AcyclicShortestPaths.hpp
            include/BellmanFordShortestPaths.hpp
            include/FlowEdge.hpp
            include/FlowNetwork.hpp
            include/FordFulkerson.hpp
            src/Graph.cpp
            src/Digraph.cpp
            src/UndirectedGraph.cpp
            src/Routes.cpp
            src/DepthFirstRoutes.cpp
            src/BreadthFirstRoutes.cpp
            src/ComponentSpreader.cpp
            src/StrongComponentSpreader.cpp
            src/MultiSourceShortestPaths.cpp
            src/DepthFirstOrder.cpp
            src/Edge.cpp
            src/EdgeWeightedGraph.cpp
            src/KruskalMinSpanningTree.cpp
            src/PrimsMinSpanningTree.cpp
            src/DirectedEdge.cpp
            src/EdgeWeightedDigraph.cpp
            src/DijkstraShortestPaths.cpp
            src/DirectedCycleFinder.cpp
            src/TopologicalOrderIterator.cpp
            src/AcyclicShortestPaths.cpp
            src/BellmanFordShortestPaths.cpp
            src/FlowEdge.cpp
            src/FlowNetwork.cpp
            src/FordFulkerson.cpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${TARGET}
    PUBLIC Container::Library
           UnionFind::Library
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
