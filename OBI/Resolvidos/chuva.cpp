//https://www.beecrowd.com.br/judge/pt/problems/view/3052?origem=1
#include <iostream>
#define MAX 504
char mapa[MAX][MAX];
bool visitado[MAX][MAX];
const int n1DirecoesI[] = {+0, +0};
const int n1DirecoesJ[] = {+1, -1};
int linhas, colunas, inicioI, inicioJ;
bool valido(int i, int j)
{
    if(i < 0 || i >= linhas || j < 0 || j >= colunas) return false;
    else if(visitado[i][j]) return false;
    else return true;
}
void dfs(int i, int j)
{
    if(mapa[i][j] != '#')
    {
        visitado[i][j] = true;
        mapa[i][j] = 'o';
        if(mapa[i + 1][j] == '#')
        {
            for(int k = 0; k < 2; k++)
            {
                if(valido(i + n1DirecoesI[k], j + n1DirecoesJ[k]))
                {
                    dfs(i + n1DirecoesI[k], j + n1DirecoesJ[k]);
                }
            }
        }
        if(mapa[i + 1][j] == '.')
        {
            if(valido(i + 1, j))
            {
                dfs(i + 1, j);
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> linhas >> colunas;
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            std::cin >> mapa[i][j];
            if(mapa[i][j] == 'o')
            {
                inicioI = i;
                inicioJ = j;
            }
        }
    }
    dfs(inicioI, inicioJ);
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            std::cout << mapa[i][j];
        }
        std::cout << '\n';
    }
}