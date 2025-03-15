//https://neps.academy/br/exercise/634
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#define MAXV 31
#define MAXV 31
std::vector<int> grafo[MAXV];
std::vector<std::string> ordena;
std::map<std::string, int> amigos;
std::string nome, nomeA, nomeB;
int gEntrada[MAXV], nAmigos, pessoas, testes;
bool khan()
{
    std::queue<int> fila;
    for(int i = 1; i <= nAmigos; i++)
    {
        if(gEntrada[i] == 0) fila.push(i);
    }
    while(!fila.empty())
    {
        int vertice = fila.front();
        for(auto it = amigos.begin(); it != amigos.end(); it++)
        {
            if(it->second == vertice)
            {
                ordena.push_back(it -> first);
            }
        }
        fila.pop();
        for(int i : grafo[vertice])
        {
            gEntrada[i]--;
            if(gEntrada[i] == 0) fila.push(i);
        }
    }
    if(ordena.size() < nAmigos) return false;
    else return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    do
    {
        std::cin >> nAmigos;
        testes++;
        if(nAmigos != 0)
        {
            for(int i = 1; i <= nAmigos; i++)
            {
                std::cin >> nome;
                amigos.insert(std::make_pair(nome, i));
            }
            for(int i = 1; i <= nAmigos; i++)
            {
                std::cin >> nomeA >> pessoas;
                if(pessoas != 0)
                {
                    for(int j = 1; j <= pessoas; j++)
                    {
                        std::cin >> nomeB;
                        grafo[amigos[nomeA]].push_back(amigos[nomeB]);
                        gEntrada[amigos[nomeB]]++;
                    }
                }
            }
            if(khan())
            {
                std::cout << "Teste " << testes << '\n';
                for(auto it = ordena.begin(); it != ordena.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << '\n';
            }
            else
            {
                std::cout << "Teste " << testes << '\n';
                std::cout << "Impossivel\n";
            }
            for(int i = 1; i <= nAmigos; i++)
            {
                grafo[i].clear();
                gEntrada[i] = 0;
            }
            ordena.clear();
        }
        else break;
    }
    while(true);
}
