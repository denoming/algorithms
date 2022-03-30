set(TARGET Hash-Test)

add_executable(${TARGET} "")

target_link_libraries(${TARGET}
    PRIVATE Hash::Library
            GTest::gtest_main
            GTest::gmock_main
)

target_include_directories(${TARGET}
    PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(
    ${TARGET}
    PRIVATE src/HashTest.cpp
            src/ChainingHashTreeTest.cpp
            src/LinearProbingHashTree.cpp
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
