/*
 TupleSplitter.h
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

#ifndef TMP_TUTORIAL_TUPLESPLITTER_H
#define TMP_TUTORIAL_TUPLESPLITTER_H

#include <tuple>
#include <math.h>

template<typename Type, size_t Mask, typename I>
struct TupleSplitter;

template<typename... Types, size_t Mask, size_t... I>
struct TupleSplitter<std::tuple<Types...>, Mask, std::index_sequence<I...>>
{
    using tupleType = typename  std::tuple<Types...>;
    using inclusive = decltype(std::tuple_cat(typename std::conditional<((Mask >> I) & 0x1),
            std::tuple<typename std::tuple_element<I, tupleType>::type>,
            std::tuple<>>::type{} ...
    ));
    using exclusive = decltype(std::tuple_cat(typename std::conditional<((Mask >> I) & 0x1) == 0,
            std::tuple<typename std::tuple_element<I, tupleType>::type>,
            std::tuple<>>::type{} ...
    ));
};

template<typename Types, size_t Mask>
struct TupleSplitterWrapper;

template<typename... Types, size_t Mask>
struct TupleSplitterWrapper<std::tuple<Types...>, Mask>
{
    using inclusiveType = typename TupleSplitter<std::tuple<Types...>, Mask, std::make_index_sequence<sizeof...(Types)>>::inclusive;
    using exclusiveType = typename TupleSplitter<std::tuple<Types...>, Mask, std::make_index_sequence<sizeof...(Types)>>::exclusive;
};

#endif //TMP_TUTORIAL_TUPLESPLITTER_H
