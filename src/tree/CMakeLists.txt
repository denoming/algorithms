set(TARGET Tree-Library)

add_library(${TARGET} INTERFACE)
add_library(Tree::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    INTERFACE include/traverse/BreadthOrderTraverse.hpp
              include/traverse/DepthInOrderTraverse.hpp
              include/traverse/DepthPostOrderTraverse.hpp
              include/traverse/DepthPreOrderTraverse.hpp
              include/BinaryTree.hpp
              include/RedBlackTree.hpp
              include/Traverse.hpp
)

target_include_directories(${TARGET}
    INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
