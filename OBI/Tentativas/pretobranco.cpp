//https://neps.academy/br/exercise/1105
//WA - 90
#include <bits/stdc++.h>
#define MAX 8
using namespace std;
const int dirI[] = {+1, -1, +0, +0};
const int dirJ[] = {+0, +0, +1, -1};
int pretaI, pretaJ, nPretas, linhas, colunas, tabuleiro[MAX][MAX], brancas, total;
bool visitado[MAX][MAX];
bool valido(int i , int j)
{
    if(i < 1 || i > linhas || j < 1 || j > colunas) return false;
    else return true;
}
void pecas(int i, int j)
{
    int proxI, proxJ, prox1, prox2;
    if(valido(i, j))
    {
        if(tabuleiro[i][j] == 1)
        {
            visitado[i][j] = true;
            for(int k = 0; k < 4; k++)
            {
                prox1 = i + dirI[k];
                prox2 = j + dirJ[k];
                if(valido(prox1, prox2))
                {
                    if(tabuleiro[prox1][prox2] == 0)
                        pecas(prox1, prox2);
                }
            }
        }
        if(tabuleiro[i][j] == 0)
        {
            for(int k = 0; k < 4; k++)
            {
                proxI = i + dirI[k];
                proxJ = j + dirJ[k];
                if(valido(proxI, proxJ))
                {
                    if(tabuleiro[proxI][proxJ] == 2) brancas++;
                }  
            }
            if(brancas == 0) 
            {
                total++;
                tabuleiro[i][j] = 2;
            }
            brancas = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> linhas >> colunas >> nPretas;
    for(int i = 0; i < nPretas; i++)
    {
        cin >> pretaI >> pretaJ;
        tabuleiro[pretaI][pretaJ] = 1;
    }
    if(tabuleiro[1][1] == 1) pecas(1, 1);
    if(tabuleiro[1][colunas] == 1) pecas(1, colunas);
    if(tabuleiro[linhas][linhas] == 1) pecas(linhas, linhas);
    if(tabuleiro[linhas][colunas] == 1) pecas(linhas, colunas);
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            if(tabuleiro[i][j] == 1 && !visitado[i][j])
            {
                pecas(i, j);
            }
        }
    }
    /*for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            cout << tabuleiro[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';*/
    cout << total << '\n';
}