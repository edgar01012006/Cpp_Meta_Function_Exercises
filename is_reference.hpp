#ifndef IS_REFERENCE_HPP
#define IS_REFERENCE_HPP

#include "integral_constant.hpp"

namespace myStd
{
    template <typename T>
    struct is_reference : false_type
    {

    };

    template <typename T>
    struct is_reference<T&> : true_type
    {

    };

    template <typename T>
    struct is_reference<T&&> : true_type
    {

    };

    template <typename T>
    constexpr bool is_reference_v = is_reference<T>::value;      
}

#endif