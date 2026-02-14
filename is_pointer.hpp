#ifndef IS_POINTER_HPP
#define IS_POINTER_HPP

#include "integral_constant.hpp"

namespace myStd 
{
    template <typename T>
    struct is_pointer : false_type
    {

    };
    
    template <typename T>
    struct is_pointer<T*> : true_type 
    {

    };

    template <typename T>
    struct is_pointer<T* const> : true_type 
    {

    };

    template <typename T> 
    struct is_pointer<T* volatile> : true_type
    {

    };

    template <typename T>
    struct is_pointer<T* const volatile> : true_type
    {

    };

    template <typename T>
    constexpr bool is_pointer_v = is_pointer<T>::value;
}

#endif