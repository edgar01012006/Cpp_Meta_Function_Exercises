#ifndef IS_VOID_HPP
#define IS_VOID_HPP

#include "integral_constant.hpp"

namespace myStd 
{
    template <typename T>
    struct is_void : false_type
    {

    };

    template <>
    struct is_void<void> : true_type 
    {

    };

    template <>
    struct is_void<const void> : true_type
    {

    };

    template <>
    struct is_void<volatile void> : true_type
    {

    };

    template <>
    struct is_void<const volatile void> : true_type
    {

    };

    template <typename T>
    constexpr bool is_void_v = is_void<T>::value;
}

#endif