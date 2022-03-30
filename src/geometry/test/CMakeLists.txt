set(TARGET "Geometry-Test")

add_executable(${TARGET} "")

target_link_libraries(${TARGET}
    PRIVATE Geometry::Library
            Tools::Library
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
            src/PointTest.cpp
            src/PointsTest.cpp
            src/LineSegmentTest.cpp
            src/LineSegmentsTest.cpp
            src/KdTreeTest.cpp
            src/LineCrossFinderTest.cpp
            src/IntervalSearchTreeTest.cpp
            src/RectCrossFinderTest.cpp
            src/GrahamScanTest.cpp)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
