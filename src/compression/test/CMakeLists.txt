set(TARGET "Compression-Test")

add_executable(${TARGET} "")

target_sources(
    ${TARGET} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/HuffmanTest.cpp"
                      "${CMAKE_CURRENT_SOURCE_DIR}/src/LzwTest.cpp")

target_link_libraries(${TARGET} PRIVATE Compression::Library)

gtest_enable(TARGET "${TARGET}" DIRECTORY "${PROJECT_OUTPUT_DIR}" DEFAULT_MAIN)
