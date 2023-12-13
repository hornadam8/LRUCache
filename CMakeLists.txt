cmake_minimum_required(VERSION 3.26)
project(lru)

set(CMAKE_CXX_STANDARD 17)

add_executable(lru main.cpp
        DoublyLinkedList.h
        DoublyLinkedList.cpp
        LruCache.h
        LruCache.cpp
        SlowFunctions.cpp
        tests/TestLruCache.cpp)
