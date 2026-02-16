#include <iostream>

template <size_t N>
struct factorial
{
    constexpr static size_t value =  N * factorial<N - 1>::value;
};

template<>
struct factorial<0>
{
    constexpr static size_t value = 1;
};

int main()
{
    std::cout << factorial<5>::value << std::endl;
    std::cout << factorial<0>::value << std::endl;
}