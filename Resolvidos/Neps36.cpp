//https://neps.academy/br/exercise/36
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAXV 10002
std::vector<int> grafo[MAXV];
int distancia[MAXV];
bool visitado[MAXV];
void caminhoMinimo(int inicio)
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
            else  distancia[vertice] = distancia[pai] + 1;
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
    int quantidadeDeCidades, origem, destino, cidadeA, cidadeB;
    std::cin >> quantidadeDeCidades >> origem >> destino;
    for(int i = 1; i < quantidadeDeCidades; i++)
    {
        std::cin >> cidadeA >> cidadeB;
        grafo[cidadeA].push_back(cidadeB);
        grafo[cidadeB].push_back(cidadeA);
    }
    caminhoMinimo(origem);
    std::cout << distancia[destino] << '\n';
}