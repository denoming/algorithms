set(TARGET "List-Library")

add_library(${TARGET})
add_library("List::Library" ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/List.hpp"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/List.cpp")

target_include_directories(${TARGET}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
