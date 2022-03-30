set(TARGET String-Library)

add_library(${TARGET})
add_library(String::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PRIVATE include/Types.hpp
            include/LsdRadixSort.hpp
            include/MsdRadixSort.hpp
            include/ThreeWayRadixSort.hpp
            include/LongestCommonPrefix.hpp
            include/TernarySearchTries.hpp
            include/KnuthMorrisPrattSubstringSearch.hpp
            include/BoyerMooreSubstringSearch.hpp
            include/RabinKarpSubstringSearch.hpp
            include/RegExpMatcher.hpp
            src/LsdRadixSort.cpp
            src/MsdRadixSort.cpp
            src/ThreeWayRadixSort.cpp
            src/LongestCommonPrefix.cpp
            src/TernarySearchTries.cpp
            src/RegExpMatcher.cpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${TARGET}
    PUBLIC Graph::Library
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()