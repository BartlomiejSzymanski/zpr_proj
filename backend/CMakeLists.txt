cmake_minimum_required(VERSION 3.22.1)
project(TicTacToe)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)


add_subdirectory(server)
add_subdirectory(proto)

# add_subdirectory(tests)
