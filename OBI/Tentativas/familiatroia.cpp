//https://neps.academy/br/exercise/512
//TLE - 0
#include <iostream>
#define TAM 50001
int main()
{
    std::ios::sync_with_stdio(false);
    bool checagem[TAM] = {};
    int n, m, familia, num1, num2;
    std::cin >> n >> m;
    familia = 0;
    for(int i = 0; i < m; i++)
    {
        std::cin >> num1 >> num2;
        for(int j = 1; j <= n; j++)
        {
            if(checagem[num1] == false && checagem[num2] == false)
            {
                familia++;
                checagem[num1] = true;
                checagem[num2] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(checagem[i] == false)
          familia++;
    }
    std::cout << familia << '\n';
}