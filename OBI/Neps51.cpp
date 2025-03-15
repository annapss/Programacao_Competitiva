//https://neps.academy/br/exercise/51
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    int p, mao1, mao2, soma;
    std::cin >> p; 
    std::cin >> mao1;
    std::cin >> mao2;
    soma = mao1 + mao2;
    if(p == 0)
    {
        if(soma % 2 == 0) std::cout << p << '\n';
        else std::cout << 1 << '\n';
    }
    else
    {
        if(soma % 2 == 0) std::cout << p << '\n';
        else std::cout << 0 << '\n';
    }
}