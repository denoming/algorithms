set(TARGET "Tree-Test")

add_executable(${TARGET} "")

target_link_libraries(${TARGET} PRIVATE Tree::Library Tools::Library)

target_include_directories(${TARGET}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(${TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/TreeTest.cpp)

gtest_enable(TARGET "${TARGET}" DIRECTORY "${PROJECT_OUTPUT_DIR}" DEFAULT_MAIN)
