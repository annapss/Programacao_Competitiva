//https://neps.academy/br/exercise/130
//WA - 0
#include <iostream>
#include <vector>
#include <algorithm>
int valorP, nHoteis, pontos = 0, total, soma;
std::vector<int> lista;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> nHoteis >> valorP;
    lista.resize(nHoteis);
    for(int i = 0; i < nHoteis; i++)
    {
        std::cin >> lista[i];
    }
    for(auto it = lista.begin(); it != lista.end(); it++)
    {
        pontos++;
        if(pontos == valorP)
        {
            if(it != lista.end() - 1)
            {
                lista.erase(std::max_element(it, lista.end()));
                pontos = 0;
            }
            else
            {
                soma += *it;
            }
        }
        else
        {
            soma += *it;
        }
    }
    for(auto it = lista.begin(); it != lista.end(); it++)
    {
        soma += *it;
    }
    std::cout << soma << '\n';
}