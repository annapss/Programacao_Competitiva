//https://neps.academy/br/exercise/303
#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#define INF (std::numeric_limits<int>::max())
#define MAXV 101
bool visitado[MAXV];
int distancia[MAXV][MAXV], quantidadeDeCidades;
void FloydWarshall()
{
    for(int k = 0; k < quantidadeDeCidades; k++)
    {
        for(int i = 0; i < quantidadeDeCidades; i++)
        {
            for(int j = 0; j < quantidadeDeCidades; j++)
            {
                if(distancia[k][j] != INF && distancia[i][k] != INF)
                {
                    if(distancia[k][j] + distancia[i][k] < distancia[i][j])
                    {
                        distancia[i][j] = distancia[i][k] + distancia[k][j];
                    }
                }
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int quantidadeDeEstradas, cidadeA, cidadeB, valor;
    std::cin >> quantidadeDeCidades >> quantidadeDeEstradas;
    for(int i = 0; i < quantidadeDeCidades; i++)
    {
        for(int j = 0; j < quantidadeDeCidades; j++)
        {
            if(i == j) distancia[i][j] = 0;
            else distancia[i][j] = INF;
        }
    }
    for(int i = 0; i < quantidadeDeEstradas; i++)
    {
        std::cin >> cidadeA >> cidadeB >> valor;
        distancia[cidadeA][cidadeB] = valor;
        distancia[cidadeB][cidadeA] = valor; 
    }
    FloydWarshall();
    int maior = 0, menor = INF;
    for(int i = 0; i < quantidadeDeCidades; i++)
    {
        for(int j = 0; j < quantidadeDeCidades; j++)
        {
            if(distancia[i][j] != 0)
            {
                if(distancia[i][j] > maior) maior = distancia[i][j];
            }
        }
        if(maior < menor) menor = maior;
        maior = 0;
    }
    std::cout << menor << '\n';
}