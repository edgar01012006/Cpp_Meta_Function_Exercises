#include <iostream>

template <size_t N, size_t It = N / 2>
struct is_prime
{
    constexpr static bool value = N % It == 0 ? false : is_prime<N, It - 1>::value;
};

template <size_t N>
struct is_prime<N, 1>
{
    constexpr static bool value = true;
};

template <>
struct is_prime<1>
{
    constexpr static bool value = false;
};

int main()
{
    std::cout << is_prime<1>::value << std::endl;
    std::cout << is_prime<3>::value << std::endl;
    std::cout << is_prime<11>::value << std::endl;
    std::cout << is_prime<17>::value << std::endl;
    std::cout << is_prime<24>::value << std::endl;
    std::cout << is_prime<93>::value << std::endl;
    std::cout << is_prime<89>::value << std::endl;
}