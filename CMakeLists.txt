cmake_minimum_required(VERSION 3.15)

project(Bamboo)

add_executable(${PROJECT_NAME} main.cpp header.h import/import.h import/import.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)