#ifndef HAS_OPERATOR_PLUS
#define HAS_OPERATOR_PLUS

#include <utility>

#include "integral_constant.hpp"

namespace myStd
{
    template <typename T>
    struct has_operator_plus
    {
        template <typename U, typename = decltype(std::declval<U>() + std::declval<U>())>
        static true_type check(int);

        template <typename U>
        static false_type check(...);

        constexpr static bool value = decltype(check<T>(0))::value;
    };

    template <typename T>
    constexpr bool has_operator_plus_v = has_operator_plus<T>::value;
}

#endif