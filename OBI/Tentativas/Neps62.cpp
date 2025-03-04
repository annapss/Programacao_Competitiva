//https://neps.academy/br/exercise/62
//TLE - 40
#include <iostream>
#include <vector>
#define MAXV 100002
std::vector<int> grafo[MAXV];
int distancia[MAXV], D;
bool visitado[MAXV];
int dfs(int vertice)
{
    visitado[vertice] = true;
    if(grafo[vertice].size() == 0)
    {
        return 0;
    }
    else
    {
        for(int i : grafo[vertice])
        {
            if(!visitado[i])
            {
                return dfs(i) + 1; 
            }
        }
    }
    
}
int main()
{
    std::ios::sync_with_stdio(false);
    int quantidadeDeVertices, cidadeA, cidadeB, inicio;
    std::cin >> quantidadeDeVertices;
    for(int i = 1; i < quantidadeDeVertices; i++)
    {
        std::cin >> cidadeA >> cidadeB;
        grafo[cidadeA].push_back(cidadeB);
        grafo[cidadeB].push_back(cidadeA);
    }
    for(int i = 1; i <= quantidadeDeVertices; i++)
    {
        if(grafo[i].size() != 0) inicio = i;
    }
}