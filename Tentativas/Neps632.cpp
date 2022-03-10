//https://neps.academy/br/exercise/632
//Run Time Error - 0
#include <iostream>
#include <vector>
#define MAX 1001
int televisao[MAX][MAX], comando1, comando2;
std::vector<int> guardar;
int linhas, colunas;
int main()
{
    std::ios::sync_with_stdio(false);
    do
    {
        std::cin >> linhas >> colunas;
        if(linhas != 0 && colunas != 0)
        {
            for(int i = 0; i < linhas; i++)
            {
                for(int j = 0; j < colunas; j++)
                {
                    std::cin >> televisao[i][j];
                }
            }
            do
            {
                std::cin >> comando1 >> comando2;
                if(comando1 != 0 && comando2 != 0)
                {
                    if(comando1 > 0)
                    {
                        for(int i = 0; i < comando1; i++)
                        {
                            for(int j = 1; j <= linhas; j++)
                            {
                                
                            }
                        }
                    }
                }
                else break;
            } while (true);
        }
        else break;
    }
    while(true);
}