set(TARGET "UnionFind-Test")

add_executable(${TARGET} "")

target_sources(
    ${TARGET}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/Common.hpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/Common.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/PercolationTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/QuickFindTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/QuickUnionTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/UnionFindTest.cpp")

target_link_libraries(${TARGET} PRIVATE UnionFind::Library)

target_include_directories(${TARGET}
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

gtest_enable(TARGET "${TARGET}" DIRECTORY "${PROJECT_OUTPUT_DIR}" DEFAULT_MAIN)
