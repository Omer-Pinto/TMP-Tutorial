//
// Created by omerp on 1/23/21.
//

#include "SuperFunctorTester.h"
#include "SuperFunctor.h"
#include <string>
#include <iostream>
#include <chrono>
#include <functional>

std::string concat2(const std::string& s1, const std::string& s2) {
    return s1 + s2;
}

std::string subString2(const std::string& s1, const int& index, const int& length) {
    return s1.substr(index, length);
}

void SuperFunctorTester::testSuperFunctorWithSubstring()
{
    auto substringFunctor0 = createSuperFunctor<0b000>(subString2);
    auto substringFunctor1 = createSuperFunctor<0b001>(subString2);
    auto substringFunctor2 = createSuperFunctor<0b010>(subString2);
    auto substringFunctor3 = createSuperFunctor<0b011>(subString2);
    auto substringFunctor4 = createSuperFunctor<0b100>(subString2);
    auto substringFunctor5 = createSuperFunctor<0b101>(subString2);
    auto substringFunctor6 = createSuperFunctor<0b110>(subString2);
    auto substringFunctor7 = createSuperFunctor<0b111>(subString2);


    //auto myFunctor8 = createFunctor<0b1000>(subString);

    std::string constant1 = "helloworldhelloworldhelloworldhelloworldhelloworldhelloworldhelloworld";
    int constant2 = 0;
    int constant3 = 4;
    std::vector<std::string> param1;
    std::vector<int> param2;
    std::vector<int> param3;
    std::vector<std::string> res0, res1, res2, res3, res4, res5, res6, res7;

    size_t vectorSize = 5;

    param1.reserve(vectorSize);
    param2.reserve(vectorSize);
    param3.reserve(vectorSize);

    for(int i = 0; i < vectorSize; i++)
    {
        std::string temp = "abcdefg" + std::to_string(i);
        param1.push_back(temp);
        param2.push_back(i % 4);
        param3.push_back(temp.length() - (i%4));
    }

    res0 = substringFunctor0(constant1, constant2, constant3);
    res1 = substringFunctor1(param1, constant2, constant3);
    res2 = substringFunctor2(constant1, param2, constant3);
    res3 = substringFunctor3(param1, param2, constant3);
    res4 = substringFunctor4(constant1, constant2, param3);
    res5 = substringFunctor5(param1, constant2, param3);
    res6 = substringFunctor6(constant1, param2, param3);
    res7 = substringFunctor7(param1, param2, param3);

    std::cout << "subString version 0" << std::endl;
    for(int i =0; i < res0.size(); i++) {
        std::cout << i << "th row in results:" << res0.at(i) << std::endl;
    }


    std::cout << "subString version 1" << std::endl;
    for(int i =0; i < res1.size(); i++) {
        std::cout << i << "th row in results:" << res1.at(i) << std::endl;
    }


    std::cout << "subString version 2" << std::endl;
    for(int i =0; i < res2.size(); i++) {
        std::cout << i << "th row in results:" << res2.at(i) << std::endl;
    }


    std::cout << "subString version 3" << std::endl;
    for(int i =0; i < res3.size(); i++) {
        std::cout << i << "th row in results:" << res3.at(i) << std::endl;
    }


    std::cout << "subString version 4" << std::endl;
    for(int i =0; i < res4.size(); i++) {
        std::cout << i << "th row in results:" << res4.at(i) << std::endl;
    }

    std::cout << "subString version 5" << std::endl;
    for(int i =0; i < res5.size(); i++) {
        std::cout << i << "th row in results:" << res5.at(i) << std::endl;
    }


    std::cout << "subString version 6" << std::endl;
    for(int i =0; i < res6.size(); i++) {
        std::cout << i << "th row in results:" << res6.at(i) << std::endl;
    }

    std::cout << "subString version 7" << std::endl;
    for(int i =0; i < res7.size(); i++) {
        std::cout << i << "th row in results:" << res7.at(i) << std::endl;
    }
}

void SuperFunctorTester::testSuperFunctorWithConcat()
{
    auto concatFunctor0 = createSuperFunctor<0b00>(concat2);
    auto concatFunctor1 = createSuperFunctor<0b01>(concat2);
    auto concatFunctor2 = createSuperFunctor<0b10>(concat2);
    auto concatFunctor3 = createSuperFunctor<0b11>(concat2);

    //auto myFunctor4 = createFunctor<0b100>(concat);

    std::string constant1 = "hello";
    std::string constant2 = "world";
    std::vector<std::string> param1;
    std::vector<std::string> param2;
    std::vector<std::string> res0, res1, res2, res3;

    size_t vectorSize = 5;

    param1.reserve(vectorSize);
    param2.reserve(vectorSize);

    for(int i = 0; i < vectorSize; i++)
    {
        param1.push_back("value" + std::to_string(i));
        param2.push_back("value" + std::to_string(i * 10));
    }

    res0 = concatFunctor0(constant1, constant2);
    res1 = concatFunctor1(param1, constant2);
    res2 = concatFunctor2(constant1, param2);
    res3 = concatFunctor3(param1, param2);

    std::cout << "concat version 0" << std::endl;
    for(int i =0; i < res0.size(); i++) {
        std::cout << i << "th row in results:" << res0.at(i) << std::endl;
    }

    std::cout << "concat version 1" << std::endl;
    for(int i =0; i < res1.size(); i++) {
        std::cout << i << "th row in results:" << res1.at(i) << std::endl;
    }

    std::cout << "concat version 2" << std::endl;
    for(int i =0; i < res2.size(); i++) {
        std::cout << i << "th row in results:" << res2.at(i) << std::endl;
    }

    std::cout << "concat version 3" << std::endl;
    for(int i =0; i < res3.size(); i++) {
        std::cout << i << "th row in results:" << res3.at(i) << std::endl;
    }
}