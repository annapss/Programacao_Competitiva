//https://neps.academy/br/exercise/28
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>
#define MAXV 102
#define INF (std::numeric_limits<int>::max())
bool visitado[MAXV];
int distancia[MAXV], quantidadeDeCidades;
std::vector<std::pair<int, int>> grafo[MAXV];
void dijkstra(int raiz)
{
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> fila;
    for(int i = 1; i <= quantidadeDeCidades; i++) distancia[i] = INF;
    distancia[raiz] = 0;
    fila.push({distancia[raiz], raiz});
    while(!fila.empty())
    {
        int atual = fila.top().second;
        fila.pop();
        for(std::pair<int, int> i : grafo[atual])
        {
            int vertice = i.second;
            int peso = i.first;
            if(!visitado[vertice])
            {
                if(distancia[atual] + peso < distancia[vertice])
                {
                    distancia[vertice] = distancia[atual] + peso;
                    fila.push({distancia[vertice], vertice});
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int quantidadesDeRelacoes, cidadeA, cidadeB, preco;
    std::cin >> quantidadeDeCidades >> quantidadesDeRelacoes;
    for(int i = 0; i < quantidadesDeRelacoes; i++)
    {
        std::cin >> cidadeA >> cidadeB >> preco;
        grafo[cidadeA].push_back(std::make_pair(preco, cidadeB));
        grafo[cidadeB].push_back(std::make_pair(preco, cidadeA));
    }
    dijkstra(1);
    std::cout << distancia[quantidadeDeCidades] << '\n';
}
