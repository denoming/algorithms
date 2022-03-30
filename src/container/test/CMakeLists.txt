set(TARGET Container-Test)

add_executable(${TARGET} "")

target_link_libraries(${TARGET}
    PRIVATE Container::Library
            GTest::gtest_main
            GTest::gmock_main
)

target_include_directories(${TARGET}
    PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(
    ${TARGET}
    PRIVATE include/ArithmeticEvaluator.hpp
            src/ListTest.cpp
            src/QueueTest.cpp
            src/PriorityQueueTest.cpp
            src/IndexPriorityQueueTest.cpp
            src/ArithmeticEvaluator.cpp
            src/StackTest.cpp
            src/ArithmeticEvaluatorTest.cpp
            src/CircularBufferTest.cpp
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
