set(TARGET Compression-Library)

add_library(${TARGET})
add_library(Compression::Library ALIAS ${TARGET})

target_sources(${TARGET}
    PRIVATE include/Huffman.hpp
            include/Lzw.hpp
            src/Huffman.cpp
            src/Lzw.cpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${TARGET}
    PUBLIC Tools::Library String::Library
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()