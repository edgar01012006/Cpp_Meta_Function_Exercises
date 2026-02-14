#ifndef IS_CONST_HPP
#define IS_CONST_HPP

#include "integral_constant.hpp"

namespace myStd
{
    template <typename T>
    struct is_const : false_type
    {
        
    };

    template <typename T>
    struct is_const<const T> : true_type // why const int& won't bind to this
    {
        
    };

    template <typename T>
    struct is_const<const volatile T> : true_type
    {

    };

    template <typename T>
    constexpr bool is_const_v = is_const<T>::value;
}

#endif