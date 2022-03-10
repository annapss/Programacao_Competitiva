//https://neps.academy/br/exercise/289
#include <iostream>
#include <vector>
#include <algorithm>
#define MAXV 100001
std::vector<int> resposta;
std::vector<int> grafo[MAXV];
int meio;
void BuscaBinaria(int esquerda, int direita, int valor, int vertice)
{
    meio = (esquerda + direita) / 2;
    while(grafo[vertice][meio] != valor)
    {
        if(grafo[vertice][meio] < valor)
        {
            esquerda = meio + 1;
        }
        if(grafo[vertice][meio] > valor)
        {
            direita = meio - 1;
        }
        meio = (direita + esquerda) / 2;
        if(esquerda > direita)
        {
            meio = -1;
            return;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int quantidadeDeIlhas, quantidadeDeIteracoes, ilhaA, ilhaB, tipo;
    std::cin >> quantidadeDeIlhas >> quantidadeDeIteracoes;
    for(int i = 0; i < quantidadeDeIteracoes; i++)
    {
        std::cin >> tipo >> ilhaA >> ilhaB;
        if(tipo == 1)
        {
            grafo[ilhaA].push_back(ilhaB);
            grafo[ilhaB].push_back(ilhaA);
        }
        else
        {
            if(grafo[ilhaA].size() != 0)
            {
                //if(!std::is_sorted(grafo[ilhaA].begin(), grafo[ilhaA].end())) 
                    std::sort(grafo[ilhaA].begin(), grafo[ilhaA].end());
                BuscaBinaria(0, grafo[ilhaA].size() - 1, ilhaB, ilhaA);
                if(meio != -1) resposta.push_back(1);
                else resposta.push_back(0);
            }
            else
            {
                resposta.push_back(0);
            }
            
        }
    }
    for(auto it = resposta.begin(); it != resposta.end(); it++)
    {
        std::cout << *it << '\n';
    }
}