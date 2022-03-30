set(TARGET Sort-Library)

add_library(${TARGET})
add_library(Sort::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PUBLIC include/BottomUpMergeSort.hpp
           include/InsertionSort.hpp
           include/MergeSort.hpp
           include/QuickSort.hpp
           include/SelectionSort.hpp
           include/ShellSort.hpp
           include/ThreeWayQuickSort.hpp
           include/QuickSelect.hpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${TARGET}
    PUBLIC Tools::Library
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
