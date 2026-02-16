#ifndef IS_CONVERTIBLE_HPP
#define IS_CONVERTIBLE_HPP

#include "utility"

#include "integral_constant.hpp"

namespace myStd
{
    template <typename From, typename To>
    struct is_convertible
    {
        template <typename F, typename T>
        static auto test(int) -> decltype(static_cast<T>(std::declval<F>()), true_type{});

        template <typename F, typename T>
        static false_type test(...);

        constexpr static bool value = decltype(test<From, To>(1))::value;
    };

    template <typename From, typename To>
    constexpr bool is_convertible_v = is_convertible<From, To>::value;
}

#endif