#include <iostream>
#include <set>
int main()
{
    std::ios::sync_with_stdio(false);
    std::set<int> compradas;
    std::set<int> carimbadas;
    int n, quantidadec, quantidadem, c, m, contagem;
    std::cin >> n >> quantidadec >> quantidadem;
    for(int i = 0; i < quantidadec; i++)
    {
        std::cin >> c;
        carimbadas.insert(c);
    }
    contagem = 0;
    for(int j = 0; j < quantidadem; j++)
    {
        std::cin >> m;
        compradas.insert(m);
    }
    for(auto it = carimbadas.begin(); it != carimbadas.end(); it++)
    {
        if(compradas.count(*it) == 0)
        contagem++;
    }
    std::cout << contagem << '\n';
}