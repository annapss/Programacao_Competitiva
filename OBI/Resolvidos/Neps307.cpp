//https://neps.academy/br/exercise/307
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#define MAXV 251
#define INF (std::numeric_limits<int>::max())
int quantidadeDeSalas, distancia[MAXV][MAXV];
void FloydWarshall()
{
    for(int k = 1; k <= quantidadeDeSalas; k++)
    {
        for(int i = 1; i <= quantidadeDeSalas; i++)
        {
            for(int j = 1; j <= quantidadeDeSalas; j++)
            {
                if(distancia[i][k] != INF && distancia[k][j] != INF)
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
    int quantidadeDeCorredores, salaA, salaB, metros;
    std::cin >> quantidadeDeSalas >> quantidadeDeCorredores;
    for(int i = 1; i <= quantidadeDeSalas; i++)
    {
        for(int j = 1; j <= quantidadeDeSalas; j++)
        {
            if(i != j) distancia[i][j] = INF;
        }
    }
    for(int i = 0; i < quantidadeDeCorredores; i++)
    {
        std::cin >> salaA >> salaB >> metros;
        distancia[salaA][salaB] = metros;
        distancia[salaB][salaA] = metros;
    }
    FloydWarshall();
    int maior = 0, menor = INF; 
    for(int i = 1; i <= quantidadeDeSalas; i++)
    {
        for(int j = 1; j <= quantidadeDeSalas; j++)
        {
            if(distancia[i][j] > maior) maior = distancia[i][j];
        }
        if(maior < menor) menor = maior;
        maior = 0;
    }
    std::cout << menor << '\n';
}