//https://neps.academy/br/exercise/493
#include <iostream>
#include <map>
#include <string>
int main()
{
    std::ios::sync_with_stdio(false);
    std::map<char,char> alfabeto;
    std::string original = "abcdefghijklmnopqrstuvwxyz", alfacrip, palavracrip, traducao;
    std::getline(std::cin, alfacrip);
    std::getline(std::cin, palavracrip);
    for(int i = 0; i < 26; i++)
    {
        alfabeto.insert(std::make_pair(alfacrip[i], original[i]));
    }
    for(int i = 0; i < palavracrip.length(); i++)
    {
        traducao.insert(i, 1, alfabeto[palavracrip[i]]);
    }
    std::cout << traducao << '\n';
}