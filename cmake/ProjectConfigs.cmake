list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/modules")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include(BuildLocation)
include(BuildType)

if(ALG_ENABLE_TESTS)
    enable_testing()
    include(AddGoogleTest)
    message(STATUS "Building with tests")
else()
    message(STATUS "Building without tests")
endif()

include(EnableCcache)
