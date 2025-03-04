//https://neps.academy/br/exercise/622
#include <iostream>
#define MAX 102
int linhas, colunas, campo[MAX][MAX], maior, somaC, somaL;
int inicioI;
int inicioJ; 
bool calculadoL[MAX][MAX], calculadoC[MAX][MAX];
bool valido(int i, int j)
{
    if(i < 0 || i >= linhas || j < 0 || j >= colunas) return false;
    else if(calculadoL[i][j] && calculadoC[i][j]) return false;
    else return true;
}
void dfsHorizontal(int i, int j)
{
    if(!valido(i,j)) return;
    if(calculadoL[i][j]) return;
    calculadoL[i][j] = true;
    somaL += campo[i][j];
    dfsHorizontal(i, j + 1);
}
void dfsVertical(int i, int j)
{
    if(!valido(i, j)) return;
    if(calculadoC[i][j]) return;
    calculadoC[i][j] = true;
    somaC += campo[i][j];
    dfsVertical(i + 1, j);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> linhas >> colunas;
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            std::cin >> campo[i][j];
        }
    }
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            dfsHorizontal(i, j);
            dfsVertical(i, j);
            if(somaC > somaL) 
            {
                if(somaC > maior) maior = somaC;
            }
            else
            {
                if(somaL > maior) maior = somaL;
            }
            somaC = 0;
            somaL = 0;
        }
    }
    std::cout << maior << '\n';
}