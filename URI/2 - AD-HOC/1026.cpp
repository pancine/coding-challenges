//C++17 30/12/2020
#include <iostream>

int main()
{
    long long int x, y;

    while (std::cin >> x >> y)
    {
        std::cout << (x ^ y) << std::endl;
    }

    return 0;
}