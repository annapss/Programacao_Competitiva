//https://neps.academy/br/exercise/518
//WA - 10
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    int hPorta, lPorta, hColchao, lColchao, cColchao;
    bool resposta;
    std::cin >> hColchao >> cColchao >> lColchao;
    std::cin >> hPorta >> lPorta;
    if(hColchao < hPorta && lColchao < lPorta)
    {
        resposta == true;
    }
    else if(lColchao < hPorta && cColchao < lPorta)
    {
        resposta = true;
    }
    else if(lColchao < lPorta && cColchao < hPorta)
    {
        resposta = true;
    }
    else
    {
        resposta = false;
    }
    if(resposta) std::cout << "S\n";
    else std::cout << "N\n"; 
}