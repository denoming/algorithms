set(TARGET "Container-Test")

add_executable(${TARGET} "")

target_link_libraries(${TARGET} PRIVATE Container::Library)

target_include_directories(${TARGET}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(
    ${TARGET}
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/ListTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/QueueTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/PriorityQueueTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/IndexPriorityQueueTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/ArithmeticEvaluator.hpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/ArithmeticEvaluator.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/StackTest.cpp"
            "${CMAKE_CURRENT_SOURCE_DIR}/src/ArithmeticEvaluatorTest.cpp")

gtest_enable(TARGET "${TARGET}" DIRECTORY "${CMAKE_BINARY_DIR}" DEFAULT_MAIN)
