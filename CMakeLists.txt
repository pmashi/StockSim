cmake_minimum_required(VERSION 3.20)

project(StockSim LANGUAGES C CXX)

add_executable(StockSim
    src/main.cpp
)

target_include_directories(StockSim PRIVATE include)