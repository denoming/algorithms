find_program(CCACHE_PROGRAM ccache)

set(CCACHE_USE_SOURCE_BASEDIR ON CACHE BOOL "Set project source dir as basedir")

if(CCACHE_PROGRAM)
    if (CCACHE_USE_SOURCE_BASEDIR)
        set(baseDir ${CMAKE_SOURCE_DIR})
    else()
        set(baseDir ${CMAKE_BINARY_DIR})
    endif()

    set(ccacheEnv
        CCACHE_CPP2=true
        CCACHE_BASEDIR=${baseDir}
        CCACHE_SLOPPINESS=pch_defines,time_macros
    )
    message(STATUS ccacheEnv=${ccacheEnv})
    foreach (lang IN ITEMS C CXX OBJC OBJCXX CUDA)
        set(CMAKE_${lang}_COMPILER_LAUNCHER ${CMAKE_COMMAND} -E env ${ccacheEnv} ${CCACHE_PROGRAM})
    endforeach ()
endif()