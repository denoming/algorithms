set(TARGET Compression-Test)

add_executable(${TARGET} "")

target_sources(${TARGET}
    PRIVATE src/HuffmanTest.cpp
            src/LzwTest.cpp
)

target_link_libraries(${TARGET}
    PRIVATE Compression::Library
            GTest::gtest_main
            GTest::gmock_main
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
