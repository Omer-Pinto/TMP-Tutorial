cmake_minimum_required(VERSION 3.17)
project(TMP_tutorial)

set(CMAKE_CXX_STANDARD 20)

add_executable(TMP_tutorial main.cpp TupleSplitter/TupleSplitter.h TupleSplitter/TupleSplitterTester.cpp TupleSplitter/TupleSplitterTester.h FunctorInputSetter/FunctorInputSetter.h FunctorInputSetter/FunctorInputSetterTester.cpp FunctorInputSetter/FunctorInputSetterTester.h)
