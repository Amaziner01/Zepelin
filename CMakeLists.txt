cmake_minimum_required(VERSION 3.16)

project(ZepelinGraphics)

file(GLOB_RECURSE SRCS "src/*.c")

add_executable(ZepelinGraphics ${SRCS})

target_link_libraries(ZepelinGraphics libatomic.a)
