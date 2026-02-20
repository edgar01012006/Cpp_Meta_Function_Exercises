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


template <size_t N, bool = is_prime<N>::value>
struct next_prime_impl;

template <size_t N>
struct next_prime_impl<N, true>
{
    static constexpr size_t value = N;
};

template <size_t N>
struct next_prime_impl<N, false>
{
    static constexpr size_t value = next_prime_impl<N + 1>::value;
};

template <size_t N>
struct next_prime
{
    static constexpr size_t value = next_prime_impl<N + 1>::value;
};


int main()
{
    std::cout << next_prime<1>::value << std::endl;
    std::cout << next_prime<3>::value << std::endl;
    std::cout << next_prime<11>::value << std::endl;
    std::cout << next_prime<17>::value << std::endl;
    std::cout << next_prime<24>::value << std::endl;
    std::cout << next_prime<93>::value << std::endl;
    std::cout << next_prime<89>::value << std::endl;
}