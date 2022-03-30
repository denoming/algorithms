set(TARGET UnionFind-Test)

add_executable(${TARGET} "")

target_sources(
    ${TARGET}
    PRIVATE include/Common.hpp
            src/Common.cpp
            src/PercolationTest.cpp
            src/QuickFindTest.cpp
            src/QuickUnionTest.cpp
            src/UnionFindTest.cpp
)

target_link_libraries(${TARGET}
    PRIVATE UnionFind::Library
            GTest::gtest_main
            GTest::gmock_main
)

target_include_directories(${TARGET}
    PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
