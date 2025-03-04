//https://neps.academy/br/exercise/296
//WA - 0
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
#define INF (std::numeric_limits<int>::max())
#define MAXV 255
std::vector<std::pair<int, int>> grafo[MAXV];
int grafo2[MAXV][MAXV], conserto,distancia[MAXV], quantidadeDeCidades, rota, quantidadeDeEstradas, cidadeA, cidadeB, pedagio, antecessor[MAXV], total;
bool visitado[MAXV];
void Dijkstra(int raiz)
{
    int atual, peso, vertice;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> fila;
    for(int i = 0; i < quantidadeDeCidades; i++) distancia[i] = INF;
    distancia[raiz] = 0;
    fila.push({distancia[raiz], raiz});
    while(!fila.empty())
    {
        atual = fila.top().second;
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
                        antecessor[vertice] = atual;
                        fila.push({distancia[vertice], vertice});
                    }
                }
            }
        }
        
    }
}
void trajeto()
{
    int anterior = antecessor[rota - 1];
    while(anterior > rota)
    {
        if(anterior == conserto) // se for o conserto
        {
            break;
        }
        else
        {
            if(anterior >= rota) // se não fizer parte da rota
            {
                anterior = antecessor[anterior];
            }
            if(anterior < rota) // se fizer parte da rota
            {
                total = distancia[anterior];
                for(int i = anterior + 1; i < rota; i++)
                {
                    total += grafo2[i][i - 1];
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    do
    {
        std::cin >> quantidadeDeCidades >> quantidadeDeEstradas >> rota >> conserto;
        if(quantidadeDeCidades != 0 && quantidadeDeEstradas != 0 && rota != 0 && conserto != 0)
        {
            for(int i = 0; i < quantidadeDeEstradas; i++)
            {
                std::cin >> cidadeA >> cidadeB >> pedagio;
                grafo2[cidadeA][cidadeB] = pedagio;
                grafo2[cidadeB][cidadeA] = pedagio;
                grafo[cidadeA].push_back(std::make_pair(cidadeB, pedagio));
                grafo[cidadeB].push_back(std::make_pair(cidadeA, pedagio)); 
            }
            Dijkstra(conserto);
            trajeto();
            if(total == 0)
            {
                std::cout << distancia[rota - 1] << '\n';
            }
            else
            {
                std::cout << total << '\n';
            }
            for(int i = 0; i < quantidadeDeCidades; i++)
            {
                std::cout << distancia[i] << " ";
            }
            std::cout << '\n';
            for(int i = 0; i < quantidadeDeCidades; i++)
            {
                std::cout << antecessor[i] << " ";
            }
            std::cout << '\n';
            visitado[MAXV] = {};
            total = 0;
        }
        else
        {
            break;
        }
    } while (true);
}