//https://www.beecrowd.com.br/judge/pt/problems/view/2833
#include <iostream>
#define MAX 17
int mestreA, mestreB, partidas[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    for(int i = 1 ; i <= 16; i++)
    {
        std::cin >> partidas[i];
        if(partidas[i] == 1) mestreA = i;
        if(partidas[i] == 9) mestreB = i;
    }
    if((mestreA - 1) / 2 == (mestreB - 1) / 2)
        std::cout << "oitavas\n";
    else if((mestreA - 1) / 4 == (mestreB - 1) / 4)
        std::cout << "quartas\n";
    else if((mestreA - 1) / 8 == (mestreB - 1) / 8)
        std::cout << "semifinal\n";
    else
        std::cout << "final\n";
}