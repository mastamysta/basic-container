#include <iostream>
#include <algorithm>

#include "container.hpp"

int main()
{
    Breadbin<float> bin;

    Breadbin<int> b2 ({ 0, 1, 2, 3});

    for (const auto& val: b2)
        std::cout << val << "\n";


    auto b3(b2);

    Breadbin<int> b4( { 1, 4, 5, 9, 8, 7, 7, 2, 12, 34, 48, 8, 7 } );

    std::sort(b4.begin(), b4.end());


    return 0;
}
