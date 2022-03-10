//https://neps.academy/br/exercise/297
//WA - 25
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
#define INF (std::numeric_limits<int>::max())
#define MAXV 1005
std::vector<std::pair<int, int>> grafo[MAXV];
bool visitado[MAXV];
int distancia[MAXV], quantidadeDePilares;
void Dijkstra(int raiz)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> fila;
    int atual, peso, vertice;
    for(int i = 0; i <= quantidadeDePilares + 1; i++) distancia[i] = INF;
    distancia[raiz] = 0;
    fila.push({raiz, distancia[raiz]});
    while(!fila.empty())
    {
        atual = fila.top().first;
        fila.pop();
        if(!visitado[atual])
        {
            visitado[atual] = true;
            for(std::pair<int, int> i : grafo[atual])
            {
                vertice = i.first;
                peso = i.second;
                if(!visitado[vertice])
                {
                    if(distancia[atual] + peso < distancia[vertice]) 
                    {
                        distancia[vertice] = distancia[atual] + peso;
                        fila.push({vertice, distancia[vertice]});
                    }
                }

            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int quantidadeDePontes, pilarA, pilarB, tabuas;
    std::cin >> quantidadeDePilares >> quantidadeDePontes;
    for(int i = 0; i < quantidadeDePontes; i++)
    {
        std::cin >> pilarA >> pilarB >> tabuas;
        grafo[pilarA].push_back({pilarB, tabuas});
        grafo[pilarB].push_back({pilarA, tabuas});
    }
    Dijkstra(0);
    std::cout << distancia[quantidadeDePilares + 1] << '\n';
}