set(TARGET String-Test)

add_executable(${TARGET} "")

target_link_libraries(${TARGET}
    PRIVATE String::Library
            GTest::gtest_main
            GTest::gmock_main
)

target_sources(
    ${TARGET}
    PRIVATE src/LsdRadixSortTest.cpp
            src/MsdRadixSortTest.cpp
            src/ThreeWayRadixSortTest.cpp
            src/LongestCommonPrefixTest.cpp
            src/TernarySearchTriesTest.cpp
            src/KnuthMorrisPrattSubstringSearchTest.cpp
            src/BoyerMooreSubstringSearchTest.cpp
            src/RabinKarpSubstringSearchTest.cpp
            src/RegExpMatcherTest.cpp
)

if (NOT CMAKE_CROSSCOMPILING)
    gtest_discover_tests(${TARGET} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()
