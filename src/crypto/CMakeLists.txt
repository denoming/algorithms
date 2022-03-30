set(TARGET Crypto-Library)

add_library(${TARGET})
add_library(Crypto::Library ALIAS ${TARGET})

target_sources(
    ${TARGET}
    PRIVATE include/Digest.hpp
            include/DigestMethod.hpp
            include/MD5.hpp
            include/SHA1.hpp
            include/UUID.hpp
            src/Digest.cpp
            src/MD5.cpp
            src/SHA1.cpp
            src/UUID.cpp
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