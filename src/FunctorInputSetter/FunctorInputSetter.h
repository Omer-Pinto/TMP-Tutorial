/*
 FunctorInputSetter.h
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

#ifndef TMP_TUTORIAL_FUNCTORINPUTSETTER_H
#define TMP_TUTORIAL_FUNCTORINPUTSETTER_H

#include <vector>
#include <tuple>

template<typename Type, size_t Mask, typename I>
struct FunctorInputSetter;

template<typename... Types, size_t Mask, size_t... I>
struct FunctorInputSetter<std::tuple<Types...>, Mask, std::index_sequence<I...>>
{
    using tupleType = typename std::tuple<Types...>;
    using type = std::tuple<typename std::conditional<(Mask >> I) & 0x1,
            const std::vector<typename std::tuple_element<I, tupleType>::type>&,
            const typename std::tuple_element<I, tupleType>::type>::type& ...>;
};

template<typename Types, size_t Mask>
struct FunctorInputSetterWrapper;

template<typename... Types, size_t Mask>
struct FunctorInputSetterWrapper<std::tuple<Types...>, Mask>
{
    using type = typename FunctorInputSetter<std::tuple<Types...>, Mask, std::make_index_sequence<sizeof...(Types)>>::type;
};

#endif //TMP_TUTORIAL_FUNCTORINPUTSETTER_H
