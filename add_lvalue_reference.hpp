#ifndef ADD_LVALUE_REFERENCE_HPP
#define ADD_LVALUE_REFERENCE_HPP

#include "is_void.hpp"

namespace myStd
{
    template <typename T>
    struct add_lvalue_reference
    {
        using type = T&;
    };

    template <typename T>
    struct add_lvalue_reference<T&>
    {
        using type = T&;
    };

    template <typename T>
    struct add_lvalue_reference<T&&>
    {
        using type = T&;
    };

    template <>
    struct add_lvalue_reference<void>
    {
        using type = void;
    };

    // TODO: Handle special cases: const void, volatile void and const volatile void

    template <typename T>
    using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;
}

#endif