cmake_minimum_required(VERSION 3.17)
project(TMP_tutorial)

set(CMAKE_CXX_STANDARD 20)

add_executable(TMP_tutorial src/main.cpp
                            src/TupleSplitter/TupleSplitterTester.cpp
                            src/FunctorInputSetter/FunctorInputSetterTester.cpp
        src/SuperSuperFunctor/SuperFunctor.h src/SuperSuperFunctor/SuperFunctorTester.cpp src/SuperSuperFunctor/SuperFunctorTester.h)
include_directories(src/SuperFunctor src/FunctorInputSetter src/TupleSplitter src/SuperSuperFunctor)