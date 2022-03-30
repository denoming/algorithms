set(TARGET Tools-Test)

add_executable(${TARGET} "")

target_link_libraries(${TARGET}
    PRIVATE Tools::Library
            GTest::gtest_main
            GTest::gmock_main
)

target_sources(
    ${TARGET}
    PRIVATE src/SequenceTest.cpp
            src/PartitionTest.cpp
            src/MemoryStreamBufferTest.cpp
            src/DynamicBitSetTest.cpp
            src/ByteOrderTest.cpp
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
