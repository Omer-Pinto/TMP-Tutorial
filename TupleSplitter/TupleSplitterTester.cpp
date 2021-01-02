/*
 TupleSplitterTester.cpp
 Copyright © 2021 Omer Pinto
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 */

#include "TupleSplitterTester.h"
#include "TupleSplitter.h"
#include <string>
#include <vector>

void TupleSplitterTester::testTupleSplitter(){
    /*
     * using std::tuple<int, float, double, bool> with mask 0b1010.
     * remember: lsb of mask refers to the  1st type of the tuple (get<0>) and the msb to the 4th type (get<3>)
     * Therefore we have: tuple<int, float, double, bool>
     *                            0,     1,      0,    1  ---> inclusive: tuple<float, bool> and exclusive tuple<int, double>
     */
    using type0 = typename TupleSplitterWrapper<std::tuple<int, float, double, bool>, 0b1010>::inclusiveType;
    using type1 = typename TupleSplitterWrapper<std::tuple<int, float, double, bool>, 0b1010>::exclusiveType;

    static_assert(std::is_same<type0 , std::tuple<float, bool>>::value, "wrong type0");
    static_assert(std::is_same<type1 , std::tuple<int, double>>::value, "wrong type1");

    // different example with tuple of size 5
    using type2 = typename TupleSplitterWrapper<std::tuple<std::string, std::vector<float>, double, std::vector<int>, int>, 0b11010>::inclusiveType;
    using type3 = typename TupleSplitterWrapper<std::tuple<std::string, std::vector<float>, double, std::vector<int>, int>, 0b11010>::exclusiveType ;

    static_assert(std::is_same<type2 , std::tuple<std::vector<float>, std::vector<int>, int>>::value, "wrong type2");
    static_assert(std::is_same<type3 , std::tuple<std::string, double>>::value, "wrong type3");

    // full mask example with tuple size 3(using inclusive type only. exclusive is the 2's complement)
    using baseTuple = std::tuple<std::string, std::vector<float>, double>;
    using type000 = typename TupleSplitterWrapper<baseTuple, 0b000>::inclusiveType;
    using type001 = typename TupleSplitterWrapper<baseTuple, 0b001>::inclusiveType;
    using type010 = typename TupleSplitterWrapper<baseTuple, 0b010>::inclusiveType;
    using type011 = typename TupleSplitterWrapper<baseTuple, 0b011>::inclusiveType;
    using type100 = typename TupleSplitterWrapper<baseTuple, 0b100>::inclusiveType;
    using type101 = typename TupleSplitterWrapper<baseTuple, 0b101>::inclusiveType;
    using type110 = typename TupleSplitterWrapper<baseTuple, 0b110>::inclusiveType;
    using type111 = typename TupleSplitterWrapper<baseTuple, 0b111>::inclusiveType;

    static_assert(std::is_same<type000 , std::tuple<>>::value,                                          "wrong type000");
    static_assert(std::is_same<type001 , std::tuple<std::string>>::value,                               "wrong type001");
    static_assert(std::is_same<type010 , std::tuple<std::vector<float>>>::value,                        "wrong type010");
    static_assert(std::is_same<type011 , std::tuple<std::string, std::vector<float>>>::value,           "wrong type011");
    static_assert(std::is_same<type100 , std::tuple<double>>::value,                                    "wrong type100");
    static_assert(std::is_same<type101 , std::tuple<std::string, double>>::value,                       "wrong type101");
    static_assert(std::is_same<type110 , std::tuple<std::vector<float>, double>>::value,                "wrong type110");
    static_assert(std::is_same<type111 , std::tuple<std::string, std::vector<float>, double>>::value,   "wrong type111");
}
