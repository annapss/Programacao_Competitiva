//https://neps.academy/br/exercise/824
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    int l, c, piso1, piso2;
    std::cin >> l >> c;
    piso1 = (c * l) + ((c - 1) * (l - 1));
    piso2 = ((c - 1) * 2) + ((l - 1) * 2);
    std::cout << piso1 << '\n';
    std::cout << piso2 << '\n'; 
}