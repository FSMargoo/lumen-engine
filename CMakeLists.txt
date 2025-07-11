cmake_minimum_required(VERSION 3.31)
project(Lumen)

set(CMAKE_CXX_STANDARD 20)

set(LumenCode
        lumen/inc/Application.h
        lumen/src/Application.cpp
        lumen/Lumen.h
        lumen/inc/EntryPoint.h
        lumen/inc/Log.h
        lumen/src/Log.cpp
        lumen/inc/Events/Event.h
        lumen/src/Event/Event.cpp
        lumen/inc/Core.h
)

add_subdirectory(./thirdparty/spdlog)

add_library(LumenEngine ${LumenCode})
add_executable(Sandbox sandbox/src/Sandbox.cpp)

target_include_directories(LumenEngine PUBLIC lumen/inc)
target_include_directories(Sandbox PRIVATE ./)

set_target_properties(LumenEngine
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
set_target_properties(Sandbox
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries(LumenEngine spdlog)
target_link_libraries(Sandbox LumenEngine)