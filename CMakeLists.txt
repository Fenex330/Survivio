#add --verbose flag for detailed status log
#add -DCMAKE_BUILD_TYPE="Debug" for development builds
#add -G"Ninja" for ninja builds
#change CMAKE_BUILD_PARALLEL_LEVEL and MULTITHREADED_BUILD to match the number of your cores/threads



cmake_minimum_required (VERSION 3.18.0) #use the latest major version available

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "FATAL: In-source builds are not allowed. You should create a separate directory for build files.")
endif()

#set (CMAKE_C_COMPILER "clang") #or gcc
#set (CMAKE_CXX_COMPILER "clang++") #or g++

project (Survivio)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_BUILD_PARALLEL_LEVEL 8)
set (MULTITHREADED_BUILD 8)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "Release")
  message (STATUS "Build type not specified: Use Release by default")
endif()

if (WIN32)
    set (SFML_INCLUDE_DIR "dependencies/SFML/windows/include")
    set (SFML_LIBRARY_DIR "dependencies/SFML/windows/lib")
endif()

if (APPLE)
    set (SFML_INCLUDE_DIR "dependencies/SFML/macOS/include")
    set (SFML_LIBRARY_DIR "dependencies/SFML/macOS/lib")
endif()

if (UNIX AND NOT APPLE) #LINUX
    set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra") #-Weffc++
    set (SFML_INCLUDE_DIR "dependencies/SFML/linux/include")
    set (SFML_LIBRARY_DIR "dependencies/SFML/linux/lib")
endif()

file (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
file (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin/docs")
file (COPY "LICENSE.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin/docs")
file (COPY "CHANGELOG.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin/docs")
file (COPY "res/graphics" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")

if (APPLE) # Mac OS needs the Frameworks and the libs
    file (COPY "dependencies/SFML/macOS/lib" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
    file (COPY "dependencies/SFML/macOS/Frameworks" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
else()
    if (NOT WIN32)
        file (COPY "${SFML_LIBRARY_DIR}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
    endif()
endif()

include_directories ("include")
include_directories (SYSTEM ${SFML_INCLUDE_DIR})
file (GLOB SRC_FILES "src/*.cpp")

if (WIN32)
    file (GLOB LIB_FILES "${CMAKE_SOURCE_DIR}/dependencies/SFML/windows/lib/*")
else()
    link_directories ("${CMAKE_CURRENT_BINARY_DIR}/bin/lib")
endif()

add_executable (Survivio WIN32 ${SRC_FILES}) #remove WIN32 if you want to keep console logs on Windows

if (WIN32)
    target_link_libraries (Survivio ${LIB_FILES})
    add_custom_command(TARGET Survivio POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${SFML_LIBRARY_DIR}" $<TARGET_FILE_DIR:Survivio>)
    add_custom_command(TARGET Survivio POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/dependencies/SFML/windows/gcc-lib" $<TARGET_FILE_DIR:Survivio>)
else()
    set_target_properties (Survivio PROPERTIES LINK_FLAGS "-Wl,-rpath,./lib")
    target_link_libraries (Survivio sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
endif()
