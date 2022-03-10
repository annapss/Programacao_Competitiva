//https://neps.academy/br/exercise/977
#include <iostream>
#include <string>
int divertido = 0, chateado = 0;
int main()
{
    std::ios::sync_with_stdio(false);
    std::string mensagem;
    std::getline(std::cin, mensagem);
    for(int i = 0; i < mensagem.length(); i++)
    {
        if(mensagem[i] == ':')
        {
            if(i + 1 < mensagem.length() && i + 2 < mensagem.length())
            {
                if(mensagem[i + 1] == '-' && mensagem[i + 2] == ')') divertido++;
                if(mensagem[i + 1] == '-' && mensagem[i + 2] == '(') chateado++;
            }
        }
    }
    if(chateado != divertido)
    {
        if(chateado > divertido)
        {
            std::cout << "chateado\n";
        }
        else
        {
            std::cout << "divertido\n";
        }
    }
    else
    {
        std::cout << "neutro\n";
    }
}