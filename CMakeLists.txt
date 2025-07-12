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
        lumen/inc/Events/KeyEvent.h
        lumen/src/Event/KeyEvent.cpp
        lumen/inc/Events/MouseEvent.h
        lumen/src/Event/MouseEvent.cpp
        lumen/inc/Events/ApplicationEvent.h
        lumen/src/Event/ApplicationEvent.cpp
        lumen/inc/Window.h
        lumen/src/Window.cpp
        lumen/inc/Platform/Windows/WindowsWindow.h
        lumen/src/Platform/Windows/WindowsWindow.cpp
)

add_subdirectory(./thirdparty/spdlog)
add_subdirectory(./thirdparty/glfw)

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

target_link_libraries(LumenEngine spdlog glfw)
target_link_libraries(Sandbox LumenEngine)