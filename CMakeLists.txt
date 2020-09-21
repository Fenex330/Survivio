#add --verbose flag for detailed status log
#add -DCMAKE_BUILD_TYPE="Debug" for development builds
#change CMAKE_BUILD_PARALLEL_LEVEL and MULTITHREADED_BUILD to match the number of your cores/threads



cmake_minimum_required (VERSION 3.18.2)
project (Survivio)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_BUILD_PARALLEL_LEVEL 8)
set (MULTITHREADED_BUILD 8)

if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "Release")
  message (STATUS "Build type not specified: Use Release by default")
endif()

if (WIN32)
    set (SFML_INCLUDE_DIR "dependencies/SFML/windows/include")
    set (SFML_LIBRARY_DIR "dependencies/SFML/windows/bin")
endif()

if (APPLE)
    set (SFML_INCLUDE_DIR "dependencies/SFML/macOS/include")
    set (SFML_LIBRARY_DIR "dependencies/SFML/macOS/lib")
endif()

if (UNIX AND NOT APPLE) #LINUX
    set (CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Weffc++")
    set (SFML_INCLUDE_DIR "dependencies/SFML/linux/include")
    set (SFML_LIBRARY_DIR "dependencies/SFML/linux/lib")
endif()

file (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
file (COPY "LICENSE.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
file (COPY "CHANGELOG.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
file (COPY "res" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")

include_directories ("include")
include_directories (SYSTEM ${SFML_INCLUDE_DIR})

if (APPLE)
     link_directories (${SFML_LIBRARY_DIR})
else()
    link_directories (SFML_LIBRARY_DIR)
endif()

file (GLOB SRC_FILES "src/*.cpp")

add_executable (Survivio ${SRC_FILES})
target_link_libraries (Survivio sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
#install (TARGETS Survivio DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
