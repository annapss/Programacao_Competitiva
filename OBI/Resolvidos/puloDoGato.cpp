//https://neps.academy/br/exercise/368
#include <bits/stdc++.h>
#define MAX 501
#define INF (std::numeric_limits<int>::max() / 2)
using namespace std;
int linhas, colunas, lajotas[MAX][MAX], distancia[MAX][MAX];
bool visitado[MAX][MAX];
bool valido(int i, int j)
{
    if(i < 1 || i > linhas || j < 1 || j > colunas) return false;
    else if(visitado[i][j] || lajotas[i][j] == 0) return false;
    else return true;
}
void bfs(int inicioI, int inicioJ)
{
    int i, j, proxI, proxJ;
    queue<pair<int,int>> fila;
    fila.push({inicioI, inicioJ});
    distancia[inicioI][inicioJ] = 0;
    while(!fila.empty())
    {
        i = fila.front().first;
        j = fila.front().second;
        fila.pop();
        if(visitado[i][j]) continue;
        visitado[i][j] = true;
        for(int dL = -2; dL <= 2; dL++)
        {
            for(int dC = -2; dC <= 2; dC++)
            {
                proxI = i + dL;
                proxJ = j + dC;
                if(valido(proxI, proxJ))
                {
                    if(distancia[i][j] + 1 < distancia[proxI][proxJ])
                    {
                        distancia[proxI][proxJ] = distancia[i][j] + 1;
                    }
                    fila.push({proxI, proxJ});
                }
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
            cin >> lajotas[i][j];
            distancia[i][j] = INF;
        }
    }
    bfs(1, 1);
    if(distancia[linhas][colunas] == INF) cout << -1 << '\n';
    else cout << distancia[linhas][colunas] << '\n';
}