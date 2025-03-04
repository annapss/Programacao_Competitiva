//https://neps.academy/br/exercise/336
//TLE - 50
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 50001
std::vector<int> grafo[MAX], pares[MAX];
bool visitado[MAX];
int nVertices, carta, vA, vB, distancia[MAX], soma;
void bfs(int inicio)
{
    std::queue<std::pair<int, int>> fila;
    int vertice, pai;
    fila.push({inicio, 0});
    while(!fila.empty())
    {
        vertice = fila.front().first;
        pai = fila.front().second;
        fila.pop();
        if(!visitado[vertice])
        {
            visitado[vertice] = true;
            if(vertice == inicio) distancia[vertice] = 0;
            else distancia[vertice] = distancia[pai] + 1;
            for(int i : grafo[vertice])
            {
                if(!visitado[i])
                {
                    fila.push({i, vertice});
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> nVertices;
    for(int i = 1; i <= nVertices; i++)
    {
        std::cin >> carta;
        pares[carta].push_back(i);
    }
    for(int i = 1; i < nVertices; i++)
    {
        std::cin >> vA >> vB;
        grafo[vA].push_back(vB);
        grafo[vB].push_back(vA);
    }
    for(int i = 1; i <= nVertices / 2; i++)
    {
        bfs(pares[i][0]);
        soma += distancia[pares[i][1]];
        for(int j = 1; j <= nVertices; j++)
        {
            distancia[j] = 0;
            visitado[j] = false;
        }
    }
    std::cout << soma << '\n';
}