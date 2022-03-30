set(TARGET Container-Library)

add_library(${TARGET})
add_library(Container::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PRIVATE include/List.hpp
            include/Queue.hpp
            include/LinkedQueue.hpp
            include/ResizableArrayQueue.hpp
            include/PriorityQueue.hpp
            include/IndexPriorityQueue.hpp
            include/Stack.hpp
            include/LinkedStack.hpp
            include/FixedArrayStack.hpp
            include/ResizableArrayStack.hpp
            include/CircularBuffer.hpp
            src/List.cpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
