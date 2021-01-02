cmake_minimum_required(VERSION 3.17)
project(TMP_tutorial)

set(CMAKE_CXX_STANDARD 20)

add_executable(TMP_tutorial src/main.cpp src/TupleSplitter/TupleSplitter.h src/TupleSplitter/TupleSplitterTester.cpp src/TupleSplitter/TupleSplitterTester.h src/FunctorInputSetter/FunctorInputSetter.h src/FunctorInputSetter/FunctorInputSetterTester.cpp src/FunctorInputSetter/FunctorInputSetterTester.h)
