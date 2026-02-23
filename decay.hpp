#ifndef DECAY_HPP 
#define DECAY_HPP

#include <utility>
#include <type_traits>

#include "remove_reference.hpp"

namespace myStd
{
    template <typename T>
    struct decay
    {
        using type = T;
    };

    template <typename T>
    struct decay<const T>
    {
        using type = typename decay<T>::type;
    };

    template <typename T>
    struct decay<const volatile T>
    {
        using type = typename decay<T>::type;
    };

    template <typename T>
    struct decay<T&> 
    {
        using type = typename decay<T>::type;
    };

    template <typename T>
    struct decay<T&&>
    {
        using type = typename decay<T>::type;
    };

    template <typename T>
    struct decay<T[]>
    {
        using type = T*;
    };

    template <typename T, size_t N>
    struct decay<T[N]>
    {
        using type = T*;
    };

    template <typename T, typename... Args>
    struct decay<T(Args...)>
    {
        using type = T(*)(Args...);
    };

    template <typename T>
    using decay_t = typename decay<T>::type;
}

#endif