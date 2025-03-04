//https://neps.academy/br/exercise/61
#include <iostream>
#define LINHAS 101
#define COLUNAS 101
char mapa[LINHAS][COLUNAS];
int linhas, colunas, posicaoi = 0, posicaoj = 0;
void trajeto(int i, int j)
{
    if(i <= 0 || i > linhas || j <= 0 || j > colunas)
        return;
    if(mapa[i][j] != '.' && mapa[i][j] != 'P')
    {
        mapa[i][j] = 'P';
        posicaoi = i;
        posicaoj = j;
        trajeto(i + 1, j);
        trajeto(i - 1, j);
        trajeto(i, j + 1);
        trajeto(i, j - 1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int posicaoinicialI = 0, posicaoinicialJ = 0;
    std::cin >> linhas >> colunas;
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            std::cin >> mapa[i][j];
            if(mapa[i][j] == 'o')
            {
                posicaoinicialI = i;
                posicaoinicialJ = j;
            }
        }
    }
    trajeto(posicaoinicialI, posicaoinicialJ);
    std::cout << posicaoi << " " << posicaoj << '\n';
}