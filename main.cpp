#include <iostream>
#include <type_traits> // Only for comparison if you want

#include "integral_constant.hpp"
#include "is_same.hpp"
#include "is_void.hpp"
#include "is_pointer.hpp"
#include "is_reference.hpp"
#include "remove_reference.hpp"
#include "add_lvalue_reference.hpp"
#include "is_const.hpp"

using namespace myStd;

int main() {
    // --- is_same Tests ---
    static_assert(is_same_v<int, int>, "is_same failed: int, int");
    static_assert(!is_same_v<int, float>, "is_same failed: int, float");

    // --- is_void Tests ---
    static_assert(is_void_v<void>, "is_void failed: void");
    static_assert(is_void_v<const void>, "is_void failed: const void");
    static_assert(!is_void_v<int>, "is_void failed: int");

    // --- is_pointer Tests ---
    static_assert(is_pointer_v<int*>, "is_pointer failed: int*");
    static_assert(is_pointer_v<const int*>, "is_pointer failed: const int*");
    static_assert(!is_pointer_v<int>, "is_pointer failed: int");

    // --- is_reference Tests ---
    static_assert(is_reference_v<int&>, "is_reference failed: int&");
    static_assert(is_reference_v<int&&>, "is_reference failed: int&&");
    static_assert(!is_reference_v<int>, "is_reference failed: int");

    // --- remove_reference Tests ---
    static_assert(is_same_v<remove_reference_t<int&>, int>, "remove_reference failed: int&");
    static_assert(is_same_v<remove_reference_t<int&&>, int>, "remove_reference failed: int&&");
    static_assert(is_same_v<remove_reference_t<int>, int>, "remove_reference failed: int");

    // --- add_lvalue_reference Tests ---
    static_assert(is_same_v<add_lvalue_reference_t<int>, int&>, "add_lvalue_ref failed: int");
    static_assert(is_same_v<add_lvalue_reference_t<int&>, int&>, "add_lvalue_ref failed: int& (collapsing)");
    static_assert(is_same_v<add_lvalue_reference_t<int&&>, int&>, "add_lvalue_ref failed: int&& (collapsing)");
    static_assert(is_same_v<add_lvalue_reference_t<void>, void>, "add_lvalue_ref failed: void");

    // --- THE BIG ONE: is_const Tests ---
    static_assert(is_const_v<const int>, "is_const failed: const int");
    static_assert(is_const_v<const volatile int>, "is_const failed: const volatile int");
    
    // This is the one we argued about:
    // It will compile (passing the test) because is_const_v is FALSE for const int&
    static_assert(!is_const_v<const int&>, "is_const truth: const int& is NOT a const type!");
    
    // To check if the REF refers to a const:
    static_assert(is_const_v<remove_reference_t<const int&>>, "This is how you check inner const");

    std::cout << "All meta-function tests passed successfully!" << std::endl;
    return 0;
}