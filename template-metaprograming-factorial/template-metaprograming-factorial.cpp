// template-metaprograming-factorial.cpp : Defines the entry point for the application.
//

#include <iostream>


template <int n>
class Fact
{
public:
    static const int val = Fact<n - 1>::val * n;
};

template<>
class Fact<0> { public: static const int val = 1; };

int main()
{
    std::cout << "fact 4 = " << Fact<4>::val << std::endl;
    std::cout << "fact 5 = " << Fact<5>::val << std::endl;
    std::cout << "fact 6 = " << Fact<6>::val << std::endl;
    std::cout << "fact 7 = " << Fact<7>::val << std::endl;

    return 0;
}
