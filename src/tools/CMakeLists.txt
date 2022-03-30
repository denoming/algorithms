set(TARGET Tools-Library)

add_library(${TARGET})
add_library(Tools::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PRIVATE include/Sequence.hpp
            include/MemoryStreamBuffer.hpp
            include/DynamicBitSet.hpp
            include/ByteOrder.hpp
            src/MemoryStreamBuffer.cpp
            src/DynamicBitSet.cpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
