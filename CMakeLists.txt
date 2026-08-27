cmake_minimum_required(VERSION 4.3)

project(sysmon VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(sysmon
    main.cpp
)

target_link_libraries(sysmon PRIVATE Qt6::Core Qt6::Widgets)
