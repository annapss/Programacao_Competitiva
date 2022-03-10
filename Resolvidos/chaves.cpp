//https://neps.academy/br/submission/272609
#include <iostream>
#include <string>
std::string codigo = {101}, digitos;
int main()
{
    std::ios::sync_with_stdio(false);
    int quantidadeDeLinhas, posicaoDaChaveFechada = 0, posicaoDaChaveAberta = 0;
    std::cin >> quantidadeDeLinhas;
    std::cin.ignore(1);
    for(int i = 0; i < quantidadeDeLinhas; i++)
    {
        std::getline(std::cin, digitos);
        codigo += digitos;
    }
    for(int i = 0; i < codigo.length(); i++)
    {
        if(codigo[i] == '{')
        {
            posicaoDaChaveAberta = i;
            if(codigo.find('}', posicaoDaChaveAberta + 1) != std::string::npos)
            {
                posicaoDaChaveFechada = codigo.find('}', posicaoDaChaveAberta + 1);
                codigo[posicaoDaChaveFechada] = ' ';
                codigo[posicaoDaChaveAberta]  = ' ';
            }
        }
    }
    if(codigo.find('{', 0) == std::string::npos && codigo.find('}', 0) == std::string::npos)
       std::cout << "S" << '\n';
    else
       std::cout << "N" << '\n';
}