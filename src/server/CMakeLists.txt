cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES src/main.cpp src/Server.cpp include/Server.h src/FileReader.cpp include/FileReader.h)

add_executable(server ${SOURCE_FILES})


