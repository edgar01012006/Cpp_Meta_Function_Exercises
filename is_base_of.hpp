#ifndef IS_BASE_OF_HPP
#define IS_BASE_OF_HPP

#include <utility>
#include <type_traits>

#include "integral_constant.hpp"

namespace myStd
{
    template <typename Base, typename Derived>
    struct is_base_of 
    {   
        static void test(Base*);

        template<typename D, typename = decltype(test(static_cast<D*>(nullptr)))>
        static true_type check(int);

        template <typename>
        static false_type check(...);

        constexpr static bool value = (std::is_class_v<Base> && std::is_class_v<Derived>) != true ? false 
                                                                                                  : decltype(check<Derived>(0))::value;
    };

    template <typename Base, typename Derived>
    constexpr bool is_base_of_v = is_base_of<Base, Derived>::value;
}

#endif