//https://neps.academy/br/exercise/24
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAXV 103
int nCastelos, pinturas, distancia[MAXV], casteloA, casteloB, cor, antecessor[MAXV], inicio, fim, cores[MAXV];
std::vector<int> grafo[MAXV];
bool visitado[MAXV];
void bfs(int inicio)
{
    std::queue<std::pair<int, int>> fila;
    fila.push({inicio, 0});
    distancia[inicio] = 0;
    int vertice, pai;
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
            antecessor[vertice] = pai;
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
void mudancaDeCor(int fim)
{
    cores[fim] = cor;
    if(fim != inicio)
    {
        mudancaDeCor(antecessor[fim]);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> nCastelos >> pinturas;
    for(int i = 1; i < nCastelos; i++)
    {
        std::cin >> casteloA >> casteloB;
        grafo[casteloA].push_back(casteloB);
        grafo[casteloB].push_back(casteloA); 
        cores[casteloB] = 0;
        cores[casteloA] = 0;
    }
    for(int i = 0; i < pinturas; i++)
    {
        std::cin >> inicio >> fim >> cor;
        bfs(inicio);
        mudancaDeCor(fim);
        for(int i = 1; i <= nCastelos; i++)
        {
            visitado[i] = false;
            distancia[i] = 0;
            antecessor[i] = 0;
        } 
    }
    for(int i = 1; i <= nCastelos; i++)
    {
        std::cout << cores[i] << " ";
    }
    std::cout << '\n';
}