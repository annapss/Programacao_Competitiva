//https://neps.academy/br/exercise/502
#include <iostream>
#define MAX 1001
int mapa[MAX][MAX], linhas, colunas, posicaoFinalI, posicaoFinalJ;
void trajeto(int i, int j)
{
    if(i < 1 || i > linhas || j < 1 || j > colunas) return;
    if(mapa[i][j] == 1)
    {
        mapa[i][j] = 0;
        posicaoFinalI = i;
        posicaoFinalJ = j;
        trajeto(i + 1, j);
        trajeto(i - 1, j);
        trajeto(i, j + 1);
        trajeto(i, j - 1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int posicaoI, posicaoJ;
    std::cin >> linhas >> colunas >> posicaoI >> posicaoJ;
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            std::cin >> mapa[i][j];
        }
    }
    mapa[posicaoI][posicaoJ] = 1;
    trajeto(posicaoI, posicaoJ);
    std::cout << posicaoFinalI << " " << posicaoFinalJ << '\n';
}