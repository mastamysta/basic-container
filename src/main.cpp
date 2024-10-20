#include <iostream>

#include "container.hpp"

int main()
{
    Breadbin<float> bin;

    Breadbin<int> b2 ({ 0, 1, 2, 3});

    for (const auto& val: b2)
        std::cout << val << "\n";

    return 0;
}
