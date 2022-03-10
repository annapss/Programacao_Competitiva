//https://neps.academy/br/exercise/17
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    int aviao, disco, quantidadeDePosicoes, apertar;
    std::cin >> quantidadeDePosicoes;
    std::cin >> disco >> aviao;
    if(aviao < disco)
       apertar = disco - aviao;
    else if(aviao > disco)
       apertar = (quantidadeDePosicoes - aviao) + disco;
    else
       apertar = 0;
    std::cout << apertar << '\n';
}