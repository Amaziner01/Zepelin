cmake_minimum_required(VERSION 3.16)

project(ZepelinGraphics)

file(GLOB_RECURSE SRCS "src/*.c")

add_compile_options(-O2)

add_executable(ZepelinGraphics ${SRCS})

file(COPY ${CMAKE_SOURCE_DIR}/res/
DESTINATION ${CMAKE_BINARY_DIR}/res/)
