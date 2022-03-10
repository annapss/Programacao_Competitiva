//https://neps.academy/br/exercise/21
#include <iostream>
#define MAX 1001
int tamanho, alturas[MAX], picos;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> tamanho;
    for(int i = 0; i < tamanho; i++)
    {
        std::cin >> alturas[i];
    }
    for(int i = 1; i < tamanho - 2; i++)
    {
        if(alturas[i] < alturas[i - 1] && alturas[i] < alturas[i + 1])
        {
            picos++;
        }
    }
    if(picos != 0) std::cout << "S\n";
    else std::cout << "N\n";
}