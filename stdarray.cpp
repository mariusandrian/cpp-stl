#include <iostream>
#include <array>

int main()
{
    // Array type integer, size 3.
    // Fyi, the 'int' is called a type template argument.
    // the 5 is a non-type template argument.
    std::array<int, 3> arr1 = {1,2,3};
    for (const auto& el : arr1)
        std::cout << el;
    std::cout << '\n';

    // You can put a constexpr var in the size,
    constexpr int len2 = 5;
    std::array<int, len2> arr2 = {};

    // but non-constexpr is not allowed.
    // int len3 = 5;
    // std::array<int, len3> arr3 = {};

    // arr.at(i) : access element at index i
    std::cout << "arr1 at 0 is " << arr1.at(0) << std::endl;

    // access out of range will throw 'std::out_of_range'
    // std::cout << "arr1 at 0 is " << arr1.at(4) << std::endl;

    // Uninitialized members gives us garbage values!
    std::array<int, 5> arr3;
    std::cout << "What happens when members are DEFAULT initialized (BAD)\n";
    for (const auto& el : arr3)
        std::cout << "el is: " << el << '\n';
    std::cout << '\n';        
    
    // Value initialized members gives us all 0s
    std::array<int, 5> arr4 = {};
    std::cout << "What happens when members are value initialized (GOOD)\n";
    for (const auto& el : arr4)
        std::cout << "el is: " << el << '\n';
    std::cout << '\n';       
}
