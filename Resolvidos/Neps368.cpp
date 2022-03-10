//https://neps.academy/br/exercise/368
#include <iostream>
#include <utility>
#include <queue>
#include <limits>
#define INF (std::numeric_limits<int>::max() / 2)
#define MAX 501
int grid[MAX][MAX], linhas, colunas, distancia[MAX][MAX];
bool visitado[MAX][MAX];
bool valido(int i, int j)
{
    if( i < 1 || i > linhas || j < 1 || j > colunas) return false;
    else if(visitado[i][j] || grid[i][j] == 0) return false;
    else return true;
}
void bfs(int inicioI, int inicioJ)
{
    int proxI, proxJ, i, j;
    std::queue<std::pair<int,int>> fila;
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
                    distancia[proxI][proxJ] = distancia[i][j] + 1;
                    fila.push({proxI, proxJ});
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> linhas >> colunas;
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            distancia[i][j] = INF;
            std::cin >> grid[i][j];
        }
    }
    bfs(1, 1);
    if(distancia[linhas][colunas] == INF) std::cout << -1 << '\n';
    else std::cout << distancia[linhas][colunas] << '\n';
}