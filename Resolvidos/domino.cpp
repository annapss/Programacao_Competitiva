//https://neps.academy/br/exercise/462
#include <iostream> 
int main()
{
     std::ios::sync_with_stdio(false);
     int n, soma;
     std::cin >> n;
     soma = 0;
     for(int i = n + 1; i >= 1; i--)
     {
          soma += i;
     }
     std::cout << soma << '\n';
}