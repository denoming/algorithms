set(TARGET Hash-Library)

add_library(${TARGET} INTERFACE)
add_library(Hash::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    INTERFACE include/ChainingHashTree.hpp
              include/LinearProbingHashTree.hpp
)

target_include_directories(${TARGET}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
