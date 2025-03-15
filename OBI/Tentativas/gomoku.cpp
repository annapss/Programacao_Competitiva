//https://neps.academy/br/exercise/37
//WA - 0
#include <bits/stdc++.h>
#define MAX 16
using namespace std;
int tabuleiro[MAX][MAX], total, jogador;
const int dirI[] = {-1, +1, +0, +0, -1, +1, +1, -1};
const int dirJ[] = {+0, +0, +1, -1, +1, -1, +1, -1};
bool um, dois, visitado[MAX][MAX];
bool valido(int i, int j)
{
    if(i < 0 || i >= 15 || j < 0 || j >= 15) return false;
    else return true;
}
void pontos(int i, int j)
{
    int proxI, proxJ;
    if(valido(i, j))
    {
        for(int k = 0; k < 8; k++)
        {
            proxI = dirI[k] + i;
            proxJ = dirJ[k] + j;
            if(valido(proxI, proxJ))
            {
                while(tabuleiro[proxI][proxJ] == tabuleiro[i][j] && valido(proxI, proxJ))
                {
                    visitado[proxI][proxJ] = true;
                    jogador = tabuleiro[proxI][proxJ];
                    proxI = proxI + dirI[k];
                    proxJ = proxJ + dirJ[k];
                    total++;
                }
                if(total == 5)
                {
                    if(jogador == 1) um = true;
                    else dois = true;
                    return;
                }
                total = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            cin >> tabuleiro[i][j];
        }
    }
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(tabuleiro[i][j] != 0)
            {
                pontos(i, j);
            }
        }
    }
    cout << '\n';
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            cout << tabuleiro[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    if(um) cout << 1 << '\n';
    else cout << 2 << '\n';
}