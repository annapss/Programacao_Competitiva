//https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> fila;
char labirinto[1001][1001];
int linhas, colunas, distancia[1001][1001];
pair<int, int> antecessor[1001][1001];
bool visitado[1001][1001];
bool valido(int i, int j)
{
    if(i < 1 || i > linhas || j < 1 || j > colunas) return false;
    else if(visitado[i][j] || labirinto[i][j] == '#') return false;
    else return true;
}
void bfs() //multisourcing
{
    int i, j, proxI, proxJ;
    while(!fila.empty())
    {
        
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
            cin >> labirinto[i][j];
            if(labirinto[i][j] == 'M')
            {
                fila.push({i, j});
                distancia[i][j] = 0;
            }
        }
    }
}