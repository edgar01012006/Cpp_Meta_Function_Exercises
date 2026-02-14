#ifndef INTEGRAL_CONSTANT_HPP
#define INTEGRAL_CONSTANT_HPP

namespace myStd 
{
    template <typename T, T v>
    struct integral_constant {
        using value_type = T;
        using type = integral_constant;
        constexpr static T value = v;
        constexpr operator value_type() const noexcept {
            return value;
        }
    };

    using true_type  = integral_constant<bool, true>;
    using false_type = integral_constant<bool, false>;
}

#endif