#include <iostream>

#include "integral_constant.hpp"
#include "is_same.hpp"
#include "is_void.hpp"
#include "is_pointer.hpp"
#include "is_reference.hpp"
#include "remove_reference.hpp"
#include "add_lvalue_reference.hpp"
#include "is_const.hpp"

#include "is_base_of.hpp"
#include "is_default_constructible.hpp"
#include "has_operator_plus.hpp"
#include "decay.hpp"

using namespace myStd;

int main()
{
    // is_same
    static_assert(is_same_v<int, int>);
    static_assert(!is_same_v<int, float>);

    // is_void
    static_assert(is_void_v<void>);
    static_assert(is_void_v<const void>);
    static_assert(!is_void_v<int>);

    // is_pointer
    static_assert(is_pointer_v<int*>);
    static_assert(!is_pointer_v<int>);

    // is_reference
    static_assert(is_reference_v<int&>);
    static_assert(is_reference_v<int&&>);
    static_assert(!is_reference_v<int>);

    // remove_reference
    static_assert(is_same_v<remove_reference_t<int&>, int>);
    static_assert(is_same_v<remove_reference_t<int&&>, int>);

    // add_lvalue_reference
    static_assert(is_same_v<add_lvalue_reference_t<int>, int&>);
    static_assert(is_same_v<add_lvalue_reference_t<int&>, int&>);
    static_assert(is_same_v<add_lvalue_reference_t<void>, void>);

    // is_const
    static_assert(is_const_v<const int>);
    static_assert(!is_const_v<const int&>);
    static_assert(is_const_v<remove_reference_t<const int&>>);

    // is_base_of
    class A {};
    class B : public A {};
    static_assert(is_base_of_v<A, A>);
    static_assert(is_base_of_v<A, B>);
    static_assert(!is_base_of_v<B, A>);

    // is_default_constructible
    class Def {};
    class NoDef { NoDef(); };
    static_assert(is_default_constructible_v<Def>);
    static_assert(!is_default_constructible_v<NoDef>);
    static_assert(is_default_constructible_v<int>);

    // has_operator_plus
    class HasPlus {
    public:
        int operator+(HasPlus);
    };
    class NoPlus {};
    static_assert(has_operator_plus_v<HasPlus>);
    static_assert(!has_operator_plus_v<NoPlus>);
    static_assert(has_operator_plus_v<int>);

    // --------------------
    // decay
    // --------------------

    // basic
    static_assert(is_same_v<decay_t<int>, int>);
    static_assert(is_same_v<decay_t<const int>, int>);
    static_assert(is_same_v<decay_t<int&>, int>);
    static_assert(is_same_v<decay_t<int&&>, int>);

    // pointers unchanged
    static_assert(is_same_v<decay_t<int*>, int*>);

    // arrays -> pointer
    static_assert(is_same_v<decay_t<int[5]>, int*>);
    static_assert(is_same_v<decay_t<int(&)[4]>, int*>);

    // functions -> function pointer
    using Fn = int(double);
    static_assert(is_same_v<decay_t<Fn>, int(*)(double)>);

    using FnRef = int(&)(double);
    static_assert(is_same_v<decay_t<FnRef>, int(*)(double)>);

    using Fn2 = void(int, char);
    static_assert(is_same_v<decay_t<Fn2>, void(*)(int, char)>);

    std::cout << "All meta-function tests passed successfully!\n";
}