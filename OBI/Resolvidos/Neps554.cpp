//https://neps.academy/br/exercise/554
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> quantidadeDeTipo;
int main()
{
    std::ios::sync_with_stdio(false);
    int quantidadeDeRotulos, tiposDeBala, bala;
    std::cin >> quantidadeDeRotulos >> tiposDeBala;
    quantidadeDeTipo.resize(tiposDeBala + 1);
    for(int i = 0; i < quantidadeDeRotulos; i++)
    {
        std::cin >> bala;
        quantidadeDeTipo[bala]++;
    }
    std::sort(quantidadeDeTipo.begin() + 1, quantidadeDeTipo.end());
    std::cout << quantidadeDeTipo[1] << '\n';
}