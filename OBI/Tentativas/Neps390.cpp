//https://neps.academy/br/exercise/390
//WA - 0
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 102
char jogo[MAX][MAX];
int tamanho, contador, caminho[MAX][MAX], comida;
std::vector<int> respostas;
bool visitado[MAX][MAX];
bool valido(int i, int j)
{
    if(i < 1 || i > tamanho || j < 1 || j > tamanho) return false;
    else if(visitado[i][j]) return false;
    else return true;
}
void percurso(int i, int j)
{
    while(valido(i, j))
    {
        contador++;
        caminho[i][j] = contador;
        visitado[i][j] = true;
        if(jogo[i][j] == 'o')
        {
            comida++;
        }
        if(jogo[i][j] == 'A')
        {
            respostas.push_back(comida);
            comida = 0;
        }
        if(i % 2 != 0)
        {
            if(j == tamanho)
            {
                percurso(i + 1, j);
            }
            else
            {
                percurso(i, j + 1);
            }
        }
        else
        {
            if(j == 1)
            {
                percurso(i + 1, j);
            }
            else
            {
                percurso(i, j - 1);
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> tamanho;
    for(int i = 1; i <= tamanho; i++)
    {
        for(int j = 1; j <= tamanho; j++)
        {
            std::cin >> jogo[i][j];
        }
    }
    percurso(1,1);
    for(int i = 1; i <= tamanho; i++)
    {
        for(int j = 1; j <= tamanho; j++)
        {
            std::cout << caminho[i][j] << " "; 
        }
        std::cout << '\n';
    }
    std::sort(respostas.begin(), respostas.end());
    std::cout << respostas[respostas.size() - 1] << '\n';
}