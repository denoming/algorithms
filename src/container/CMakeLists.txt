set(TARGET "Container-Library")

add_library(${TARGET})
add_library("Container::Library" ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/List.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/Queue.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/LinkedQueue.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/ResizableArrayQueue.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/PriorityQueue.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/IndexPriorityQueue.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/Stack.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/LinkedStack.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/FixedArrayStack.hpp"
           "${CMAKE_CURRENT_SOURCE_DIR}/include/ResizableArrayStack.hpp"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/List.cpp")

target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
