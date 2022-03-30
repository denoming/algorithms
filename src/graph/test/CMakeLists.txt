set(TARGET Graph-Test)

add_executable(${TARGET} "")

target_link_libraries(${TARGET}
    PRIVATE Graph::Library
            UnionFind::Library
            GTest::gtest_main
            GTest::gmock_main
)

target_include_directories(${TARGET}
   PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(
    ${TARGET}
    PRIVATE include/Common.hpp
            src/Common.cpp
            src/DigraphTest.cpp
            src/RoutesTest.cpp
            src/UndirectedGraphTest.cpp
            src/UndirectedRoutesTest.cpp
            src/MultiSourceShortestPathsTest.cpp
            src/DepthFirstOrderTest.cpp
            src/ComponentSpreaderTest.cpp
            src/StrongComponentSpreaderTest.cpp
            src/MinSpanningTreeTest.cpp
            src/DijkstraShortestPathsTest.cpp
            src/DirectedCycleFinderTest.cpp
            src/TopologicalOrderIteratorTest.cpp
            src/AcyclicShortestPathsTest.cpp
            src/BellmanFordShortestPathsTest.cpp
            src/FordFulkersonTest.cpp
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
