cmake_minimum_required(VERSION 3.20)
project(untitled)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.1.3/gcc_64/lib/cmake/)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

include_directories(
        cmake-build-debug
)

add_executable(untitled Interface/Sources/main.cpp Interface/Headers/MainWindow.h Interface/Sources/MainWindow.cpp)

target_link_libraries(untitled PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
