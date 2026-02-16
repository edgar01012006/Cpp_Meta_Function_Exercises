#include <iostream>

template <size_t N>
struct fibonacci
{
    constexpr static size_t value = fibonacci<N - 1>::value + fibonacci<N - 2>::value;
};

template<>
struct fibonacci<0>
{
    constexpr static size_t value = 0;
};

template<>
struct fibonacci<1>
{
    constexpr static size_t value = 1;
};

int main()
{
    std::cout << fibonacci<3>::value << std::endl;
    std::cout << fibonacci<5>::value << std::endl;
    std::cout << fibonacci<0>::value << std::endl;
    std::cout << fibonacci<6>::value << std::endl;
}