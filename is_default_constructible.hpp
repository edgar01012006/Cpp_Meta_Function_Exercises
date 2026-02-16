#ifndef IS_DEFAULT_CONSTRUCTIBLE_HPP
#define IS_DEFAULT_CONSTRUCTIBLE_HPP

#include <utility>

#include "integral_constant.hpp"

namespace myStd
{
    template <typename T>
    struct is_default_constructible
    {
        template <typename U, typename = decltype(U())>
        static true_type check(int);

        template <typename>
        static false_type check(...);

        constexpr static bool value = decltype(check<T>(0))::value;
    };

    template <typename T>
    constexpr bool is_default_constructible_v = is_default_constructible<T>::value;
}

#endif