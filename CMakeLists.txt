cmake_minimum_required(VERSION 3.10)
project(my_binary_tree_1_0)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_binary_tree_1_0 main.cpp tree.cpp tree.h NODE.h Data.h bst.h bst.cpp AVL.h AVL.cpp)