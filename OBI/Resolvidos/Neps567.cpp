//https://neps.academy/br/exercise/567
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int pele[MAX][MAX], manchas, linhas, colunas;
const int dirI[] = {+1, -1, +0, +0};
const int dirJ[] = {+0, +0, +1, -1};
bool visitado[MAX][MAX];
bool valido(int i , int j)
{
    if( i < 1 || i > linhas || j < 1 || j > colunas) return false;
    else if(visitado[i][j] || pele[i][j] == 0) return false;
    else return true;
}
void bfs(int inicioI, int inicioJ)
{
    int i, j, proxI, proxJ; 
    queue<pair<int,int>> fila;
    fila.push({inicioI, inicioJ});
    while(!fila.empty())
    {
        i = fila.front().first;
        j = fila.front().second;
        fila.pop();
        if(visitado[i][j]) continue;
        visitado[i][j] = true;
        for(int k = 0; k < 4; k++)
        {
            proxI = i + dirI[k];
            proxJ = j + dirJ[k];
            if(valido(proxI, proxJ))
            {
                fila.push({proxI, proxJ});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> linhas >> colunas;
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            cin >> pele[i][j];
        }
    }
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            if(valido(i, j))
            {
                manchas++;
                bfs(i, j);
            }
        }
    }
    cout << manchas << '\n';
}