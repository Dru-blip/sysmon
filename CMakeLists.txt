cmake_minimum_required(VERSION 4.3)
project(sysmon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(wxWidgets REQUIRED COMPONENTS gl core base)
include(${wxWidgets_USE_FILE})

set(SOURCES main.cpp view/App.cpp view/MainFrame.cpp view/ProcessList.cpp core/Stats.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE ${wxWidgets_LIBRARIES})
