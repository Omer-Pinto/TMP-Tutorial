/*
 FunctorInputSetterTester.cpp
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

#include "FunctorInputSetterTester.h"
#include "FunctorInputSetter.h"
#include <string>
#include <vector>
#include <tuple>

void FunctorInputSetterTester::testFunctorInputSetter() {
    // full mask example with tuple size 3(using inclusive type only. exclusive is the 2's complement)
    using baseTuple = std::tuple<std::string, float, double>;
    using type000 = typename FunctorInputSetterWrapper<baseTuple, 0b000>::type;
    using type001 = typename FunctorInputSetterWrapper<baseTuple, 0b001>::type;
    using type010 = typename FunctorInputSetterWrapper<baseTuple, 0b010>::type;
    using type011 = typename FunctorInputSetterWrapper<baseTuple, 0b011>::type;
    using type100 = typename FunctorInputSetterWrapper<baseTuple, 0b100>::type;
    using type101 = typename FunctorInputSetterWrapper<baseTuple, 0b101>::type;
    using type110 = typename FunctorInputSetterWrapper<baseTuple, 0b110>::type;
    using type111 = typename FunctorInputSetterWrapper<baseTuple, 0b111>::type;

    static_assert(std::is_same<type000 , std::tuple<const std::string&, const float&, const double&>>::value,                                           "wrong type000");
    static_assert(std::is_same<type001 , std::tuple<const std::vector<std::string>&, const float&, const double&>>::value,                              "wrong type001");
    static_assert(std::is_same<type010 , std::tuple<const std::string&, const std::vector<float>&, const double&>>::value,                              "wrong type010");
    static_assert(std::is_same<type011 , std::tuple<const std::vector<std::string>&, const std::vector<float>&, const double&>>::value,                 "wrong type011");
    static_assert(std::is_same<type100 , std::tuple<const std::string&, const float&, const std::vector<double>&>>::value,                              "wrong type100");
    static_assert(std::is_same<type101 , std::tuple<const std::vector<std::string>&, const float&, const std::vector<double>&>>::value,                 "wrong type101");
    static_assert(std::is_same<type110 , std::tuple<const std::string&, const std::vector<float>&, const std::vector<double>&>>::value,                 "wrong type110");
    static_assert(std::is_same<type111 , std::tuple<const std::vector<std::string>&, const std::vector<float>&, const std::vector<double>&>>::value,    "wrong type111");

    // different example with tuple of size 5
    using type = typename FunctorInputSetterWrapper<std::tuple<std::string, float, double, int, bool>, 0b11010>::type;
    static_assert(std::is_same<type, std::tuple<const std::string&, const std::vector<float>&, const double&, const std::vector<int>&, const std::vector<bool>&>>::value, "wrong type");
}
