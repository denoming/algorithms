set(TARGET "Hash-Test")

add_executable(${TARGET} "")

target_link_libraries(${TARGET} PRIVATE Hash::Library)

target_include_directories(${TARGET}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(
    ${TARGET}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/HashTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/ChainingHashTreeTest.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/LinearProbingHashTree.cpp)

gtest_enable(TARGET "${TARGET}" DIRECTORY "${PROJECT_OUTPUT_DIR}" DEFAULT_MAIN)
