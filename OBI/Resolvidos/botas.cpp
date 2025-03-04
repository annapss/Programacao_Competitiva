//https://neps.academy/br/exercise/19
#include <iostream>
#define TAM 61
int esquerda[TAM], direita[TAM];
int main()
{
    std::ios::sync_with_stdio(false);
    int tamanho, numerodebotas, pares = 0;
    char lado;
    std::cin >> numerodebotas;
    for(int i = 0; i < numerodebotas; i++)
    {
        std::cin >> tamanho >> lado;
        if(lado == 'D')
           direita[tamanho]++;
        else
           esquerda[tamanho]++;
    }
    for(int i = 0; i <= TAM; i++)
    {
        if(esquerda[i] <= direita[i])
           pares += esquerda[i];
        if(direita[i] < esquerda[i])
          pares += direita[i];
    }
    std::cout << pares << '\n';
}