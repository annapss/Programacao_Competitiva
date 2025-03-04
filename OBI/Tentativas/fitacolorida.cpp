//https://neps.academy/br/exercise/49
//WA - 10
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10000
int main()
{
    std::ios::sync_with_stdio(false);
    std::queue<int> posicaoDoZero;
    std::vector<int> resposta;
    int fita[MAX], quantidadeDeQuadrados, topo, final;
    std::cin >> quantidadeDeQuadrados;
    for(int i = 0; i < quantidadeDeQuadrados; i++)
    {
        std::cin >> fita[i];
        if(fita[i] == 0)
        {
            posicaoDoZero.push(i);
        }
    }
    for(int i = 0; i < quantidadeDeQuadrados; i++)
    {
        if(fita[i] == -1)
        {
            topo = std::abs(posicaoDoZero.front() - i);
            final = std::abs(posicaoDoZero.back() - i);
            if(topo < final) resposta.push_back(topo);
            else if(final < topo) resposta.push_back(final);
            else resposta.push_back(topo);           
        }
        else
        {
            resposta.push_back(0);
            posicaoDoZero.push(posicaoDoZero.front());
            posicaoDoZero.pop();
        }
    }
    for(auto it = resposta.begin(); it != resposta.end(); it++)
    {
        std::cout << *it << " ";;
    }
    std::cout << '\n';
}