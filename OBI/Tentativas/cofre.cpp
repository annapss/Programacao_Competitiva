//https://neps.academy/br/exercise/16
//50 pontos - TLE
#include <iostream>
#define MAX 100002
int numerosacessados[10];
int main()
{
    std::ios::sync_with_stdio(false);
    int posicoes[MAX], barra[MAX], quantidadedeposicoes, quantidadedenumeros, primeironumero;
    std::cin >> quantidadedenumeros >> quantidadedeposicoes;
    for(int i = 1; i <= quantidadedenumeros; i++)
       std::cin >> barra[i];
    for(int i = 0; i < quantidadedeposicoes; i++)
       std::cin >> posicoes[i];
    numerosacessados[barra[1]]++;
    for(int i = 0; i < quantidadedeposicoes; i++)
    {
        if(i != 0)
        {
            if(posicoes[i] > posicoes[i-1])
            {
                for(int j = posicoes[i- 1] + 1; j <= posicoes[i]; j++)
                   numerosacessados[barra[j]]++;
            }
            else
            {
                for(int j = posicoes[i]; j < posicoes[i - 1]; j++)
                   numerosacessados[barra[j]]++;
            }   
        }
    }
    for(int i = 0; i < 10; i++)
    {
        std::cout << numerosacessados[i] << " ";
    }
    std::cout << '\n';
}