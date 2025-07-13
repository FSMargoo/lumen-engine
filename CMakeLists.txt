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
        lumen/inc/Layer.h
        lumen/src/Layer.cpp
        lumen/inc/LayerStack.h
        lumen/src/LayerStack.cpp

        lumen/inc/ImGUI/ImGUILayer.h
        lumen/src/ImGUI/ImGUILayer.cpp

        thirdparty/glad/src/glad.c
        lumen/inc/Input.h
        lumen/inc/Platform/Windows/WindowsInput.h
        lumen/src/Platform/Windows/WindowsInput.cpp
)

set(IMGUICode thirdparty/imgui/imgui.cpp thirdparty/imgui/imgui_draw.cpp thirdparty/imgui/imgui_widgets.cpp
        thirdparty/imgui/backends/imgui_impl_opengl3.cpp thirdparty/imgui/backends/imgui_impl_glfw.cpp
        thirdparty/imgui/imgui_demo.cpp thirdparty/imgui/imgui_draw.cpp thirdparty/imgui/imgui_tables.cpp)

add_subdirectory(./thirdparty/spdlog)
add_subdirectory(./thirdparty/glfw)

add_library(IMGUI ${IMGUICode})
add_library(LumenEngine ${LumenCode})
add_executable(Sandbox sandbox/src/Sandbox.cpp)

target_include_directories(LumenEngine PUBLIC lumen/inc)
target_include_directories(LumenEngine PUBLIC ./thirdparty/glad/include)
target_include_directories(LumenEngine PUBLIC ./thirdparty/imgui)

target_include_directories(IMGUI PUBLIC ./thirdparty/imgui)

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

target_link_libraries(IMGUI glfw opengl32)
target_link_libraries(LumenEngine spdlog glfw opengl32 IMGUI)
target_link_libraries(Sandbox LumenEngine)