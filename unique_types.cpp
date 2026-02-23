#include <iostream>

template<typename T, typename... List>
struct contains_type;

template<typename T>
struct contains_type<T> : std::false_type {};

template<typename T, typename First, typename... Rest>
struct contains_type<T, First, Rest...> : std::conditional_t<std::is_same_v<T, First>, std::true_type, contains_type<T, Rest...>> {};

template<typename... Types>
struct unique_types;

template<>
struct unique_types<> : std::true_type {};

template<typename First, typename... Rest>
struct unique_types<First, Rest...> : std::conditional_t<contains_type<First, Rest...>::value, std::false_type, unique_types<Rest...>> {};

int main() {
    static_assert(unique_types<int, double, char>::value, "Should be unique");
    static_assert(!unique_types<int, double, int>::value, "Has duplicate");

    std::cout << "unique_types tests passed!" << std::endl;
}