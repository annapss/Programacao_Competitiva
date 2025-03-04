//https://neps.academy/br/exercise/543
//WA - 0
#include <iostream>
#define MAX 101
bool visitado[MAX][MAX], bloqueado[MAX][MAX];
char mapa[MAX][MAX];
int linhas, colunas, nBombas, bombaI, bombaJ, navios;
const int dirI[] = {+0, +0};
const int dirJ[] = {+1, -1};
const int nDirecoes = 2;
bool valido(int i, int j)
{
    if(i < 0 || i > linhas || j < 0 || j > colunas) return false;
    else if(visitado[i][j] || bloqueado[i][j]) return false;
    else return true;
}
bool dfs(int i, int j)
{
    int proxI, proxJ;
    visitado[i][j] = true;
    for(int k = 0; k < nDirecoes; k++)
    {
        proxI = i + dirI[k];
        proxJ = j + dirJ[k];
        if(valido(proxI, proxJ))
        {
            if(mapa[proxI][proxJ] == '#')
            {
                return false;
            }
            dfs(proxI, proxJ);
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> linhas >> colunas;
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            std::cin >> mapa[i][j];
            if(mapa[i][j] == '.') bloqueado[i][j] = true;
        }
    }
    std::cin >> nBombas;
    for(int i = 0; i < nBombas; i++)
    {
        std::cin >> bombaI >> bombaJ;
        if(mapa[bombaI][bombaJ] == '#')
        {
            mapa[bombaI][bombaJ] = 'B';
        }
    }
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            if(valido(i, j))
            {
                if(mapa[i][j] == 'B')
                {
                    if(dfs(i, j)) navios++;
                }
            }
            std::cout << mapa[i][j];
        }
        std::cout << '\n';
    }
    std::cout << navios << '\n';
}