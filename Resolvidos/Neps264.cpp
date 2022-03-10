//https://neps.academy/br/exercise/264
#include <iostream>
#include <queue>
#define MAXV 100001
int nBancos, nOperacoes, bancoA, bancoB, tamanho[MAXV], pai[MAXV];
std::vector<char> resposta;
char tipo;
int busca(int item)
{
    if(pai[item] == item) return item;
    else
    {
        pai[item] = busca(pai[item]);
        return pai[item];
    }
    
}
void uniao(int x, int y)
{
    int rX = busca(x);
    int rY = busca(y);
    if(rX != rY)
    {
        if(tamanho[rX] < tamanho[rY])
        {
            pai[rX] = rY;
            tamanho[rY] += tamanho[rX];
        }
        else
        {
            pai[rY] = rX;
            tamanho[rX] += tamanho[rY];
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> nBancos >> nOperacoes;
    for(int i = 1; i <= nBancos; i++)
    {
        pai[i] = i;
        tamanho[i] = 1;
    }
    for(int i = 0; i < nOperacoes; i++)
    {
        std::cin >> tipo >> bancoA >> bancoB;
        if(tipo == 'C')
        {
            if(busca(bancoB) == busca(bancoA))
            {
                resposta.push_back('S');
            }
            else
            {
                resposta.push_back('N');
            }
        }
        else
        {
            uniao(bancoA, bancoB);
        }
    }
    for(auto it = resposta.begin(); it != resposta.end(); it++)
    {
        std::cout << *it << '\n';
    }
}