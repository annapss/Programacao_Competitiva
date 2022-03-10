//https://neps.academy/br/exercise/824
#include <iostream>
#include <cmath>
int main()
{
    std::ios::sync_with_stdio(false);
    int a, b, c;
    std::cin >> a >> b >> c;
    if(std::abs(b - a) < std::abs(c - b))
      std::cout << "1\n";
    if(std::abs(b - a) > std::abs(c - b))
      std::cout << "-1\n";
    if(std::abs(b - a) == std::abs(b - c))
      std::cout << "0\n";
}