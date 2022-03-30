set(TARGET UnionFind-Library)

add_library(${TARGET})
add_library(UnionFind::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PRIVATE include/Percolation.hpp
            include/QuickFind.hpp
            include/QuickUnion.hpp
            include/UnionFind.hpp
            src/Percolation.cpp
            src/QuickFind.cpp
            src/QuickUnion.cpp
            src/UnionFind.cpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
