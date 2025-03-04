//https://neps.academy/br/exercise/1022
//WA - 10
#include <iostream>
#include <algorithm>
#include <vector>
double tamanho, nCidades, distC, vizinhanca;
std::vector<double> estrada;
std::vector<double> resposta;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> tamanho >> nCidades;
    for(int i = 0; i < nCidades; i++)
    {
        std::cin >> distC;
        estrada.push_back(distC);
    }
    std::sort(estrada.begin(), estrada.end());
    for(auto it = estrada.begin(); it != estrada.end(); it++)
    {
        if(it == estrada.begin())
        {
            vizinhanca = *it + ((std::abs(*it - *(it + 1))) / 2);
            resposta.push_back(vizinhanca);
        }
        if(it == estrada.end() - 1)
        {
            vizinhanca = std::abs(*it - tamanho) + ((std::abs(*it - *(it - 1))) / 2);
            resposta.push_back(vizinhanca);
        }
    }
    std::sort(resposta.begin(), resposta.end());
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << resposta[0] << '\n';
}