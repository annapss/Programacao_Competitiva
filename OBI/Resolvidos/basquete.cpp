//https://neps.academy/br/exercise/162
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    int d;
    std::cin >> d;
    if(d >= 0 && d <= 800)
    {
        std::cout << "1\n";
    }
    if(d > 800 && d <= 1400)
    {
        std::cout << "2\n";
    }
    if(d > 1400 && d <= 2000)
    {
        std::cout << "3\n";
    }
}