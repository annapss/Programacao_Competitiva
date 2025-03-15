//https://neps.academy/br/exercise/825
#include <iostream>
#define MAX 501
int linhas, proxI, proxJ;
const int dirI[] = {+1, -1, +0, +0};
const int dirJ[] = {+0, +0, +1, -1};
const int nDirecoes = 4;
bool visitado[MAX][MAX];
char forca, mapa[MAX][MAX];
bool valido(int i, int j)
{
    if(i < 0 || i >= linhas || j < 0 || j >= linhas) return false;
    else if(visitado[i][j] || forca < mapa[i][j]) return false;
    else return true;
}
void dfs(int i, int j)
{
    if(mapa[i][j] <= forca)
    {
        visitado[i][j] = true;
        mapa[i][j] = '*';
        for(int k = 0; k < nDirecoes; k++)
        {
            proxI = i + dirI[k];
            proxJ = j + dirJ[k];
            if(valido(proxI, proxJ))
            {
                dfs(proxI, proxJ);
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> linhas >> forca;
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < linhas; j++)
        {
            std::cin >> mapa[i][j];
        }
    }
    dfs(0, 0);
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < linhas; j++)
        {
            std::cout << mapa[i][j];
        }
        std::cout << '\n';
    }
}