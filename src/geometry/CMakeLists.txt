set(TARGET Geometry-Library)

add_library(${TARGET})
add_library(Geometry::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PRIVATE include/Point.hpp
            include/Points.hpp
            include/LineSegment.hpp
            include/LineSegments.hpp
            include/KdTree.hpp
            include/KdTreeEx.hpp
            include/LineCrossFinder.hpp
            include/IntervalSearchTree.hpp
            include/Rect.hpp
            include/Rects.hpp
            include/RectCrossFinder.hpp
            include/GrahamScan.hpp
            src/KdTree.cpp
            src/KdTreeEx.cpp
            src/LineSegment.cpp
            src/LineSegments.cpp
            src/Point.cpp
            src/Points.cpp
            src/LineCrossFinder.cpp
            src/Rect.cpp
            src/RectCrossFinder.cpp
            src/GrahamScan.cpp
)

target_include_directories(${TARGET}
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${TARGET}
    PUBLIC Container::Library
           Sort::Library
)

if(ALG_ENABLE_TESTS)
    add_subdirectory(test)
endif()
