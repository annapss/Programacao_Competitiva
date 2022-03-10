//https://neps.academy/br/exercise/331
#include <iostream>
#include <queue>
#include <vector>
#define MAXV 50001
#define MAXE 200001
int gEntrada[MAXV], nTarefas, nDependencias;
std::vector<int> ordena, grafo[MAXV];
bool khan()
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> fila;
    for(int i = 0; i < nTarefas; i++)
    {
        if(gEntrada[i] == 0) fila.push(i);
    }
    while(!fila.empty())
    {
        int vertice = fila.top();
        ordena.push_back(vertice);
        fila.pop();
        for(int i : grafo[vertice])
        {
            gEntrada[i]--;
            if(gEntrada[i] == 0) fila.push(i);
        }
    }
    if(ordena.size() < nTarefas) return false;
    else return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int vA, vB;
    std::cin >> nTarefas >> nDependencias;
    for(int i = 0; i < nDependencias; i++)
    {
        std::cin >> vA >> vB;
        grafo[vA].push_back(vB);
        gEntrada[vB]++;
    }
    if(khan())
    {
        for(auto it = ordena.begin(); it != ordena.end(); it++)
        {
            std::cout << *it << '\n';
        }
    }
    else
    {
        std::cout << "*\n";
    }
}