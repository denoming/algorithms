set(TARGET Sort-Test)

add_executable(${TARGET} "")

target_link_libraries(${TARGET}
    PRIVATE Sort::Library
            GTest::gtest_main
            GTest::gmock_main
)

target_sources(
    ${TARGET}
    PRIVATE src/BottomUpMergeSortTest.cpp
            src/HeapSortTest.cpp
            src/InsertionSortTest.cpp
            src/MergeSortTest.cpp
            src/QuickSortTest.cpp
            src/SelectionSortTest.cpp
            src/ShellSortTest.cpp
            src/ThreeWayQuickSortTest.cpp
            src/QuickSelectTest.cpp
            src/BubbleSortTest.cpp
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
