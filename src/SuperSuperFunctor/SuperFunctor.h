/*
 SuperFunctor.h
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

#ifndef TMP_TUTORIAL_SUPERFUNCTOR_H
#define TMP_TUTORIAL_SUPERFUNCTOR_H

#include <tuple>
#include <vector>
#include <cmath>
#include "FunctorInputSetter.h"

template<typename T, size_t Mask, typename S>
class SuperFunctor;

template<typename Out, typename... FullInputTypes, size_t Mask, typename... TransformedType>
class SuperFunctor<Out (const FullInputTypes&...), Mask, std::tuple<TransformedType...>> {
public:
    using Func = Out (*)(const FullInputTypes&...);

    explicit SuperFunctor(Func f): func(f) {}

private:
    Func func;

    template<typename Type>
    inline const Type& extractValue(const Type& val, int index) {
        return val;
    }

    template<typename Type>
    inline const Type& extractValue(const std::vector<Type>& vectorOfValues, int index) {
        return vectorOfValues[index];
    }

    template<typename Type>
    size_t getSize(const std::vector<Type>& vec) {
        return vec.size();
    }

    template<typename Type>
    size_t getSize(const Type& val) {
        return 1;
    }

    size_t findSize(const TransformedType&... input) {
        std::vector<size_t> sizes;
        sizes.reserve(sizeof...(TransformedType));
        (sizes.push_back(getSize(input)),...);
        return *max_element(sizes.begin(), sizes.end());
    }

public:
    std::vector<Out> operator()(const TransformedType&... input) {
        std::vector<Out> results;
        size_t size = findSize(input...);
        results.reserve(size);

        for(int i = 0; i < size; i++) {
            results.push_back(func(extractValue(input, i)...));
        }

        return results;
    }
};

template<size_t Mask, typename Out, typename... FullInputTypes>
auto createSuperFunctor(Out (*t) (const FullInputTypes&...)) {
    static_assert(Mask < std::pow(2, sizeof...(FullInputTypes)), "Mask too big");
    return SuperFunctor<Out (const FullInputTypes&...), Mask,
            typename FunctorInputSetterWrapper<std::tuple<FullInputTypes...>, Mask>::type> {t};
}

#endif //TMP_TUTORIAL_SUPERFUNCTOR_H
