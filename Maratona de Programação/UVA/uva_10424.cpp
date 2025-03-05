//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1365
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string nomeA, nomeB;
    int totalNomeA, totalNomeB;
    float porcentagem;
    while(getline(cin, nomeA))
    {
        getline(cin, nomeB);
        totalNomeA = 0;
        totalNomeB = 0;
        for(int i = 0; i < nomeA.length(); i++)
        {
            if((nomeA[i] >= 'a' && nomeA[i] <= 'z'))
            {
                totalNomeA += nomeA[i] - ('a' - 1);
            }
            else if(nomeA[i] >= 'A' && nomeA[i] <= 'Z')
            {
                totalNomeA += nomeA[i] - ('A' - 1);
            }
        }
        int temp, resto;
        while(totalNomeA >= 10)
        {
            temp = totalNomeA, resto;
            totalNomeA = 0;
            while(temp >= 10)
            {
                resto = temp % 10;
                temp = temp / 10;
                totalNomeA += resto;
            }
            totalNomeA += temp;
        }
        for(int i = 0; i < nomeB.length(); i++)
        {
            if((nomeB[i] >= 'a' && nomeB[i] <= 'z'))
            {
                totalNomeB += nomeB[i] - ('a' - 1);
            }
            else if(nomeB[i] >= 'A' && nomeB[i] <= 'Z')
            {
                totalNomeB += nomeB[i] - ('A' - 1);
            }
        }
        while(totalNomeB >= 10)
        {
            temp = totalNomeB, resto;
            totalNomeB = 0;
            while(temp >= 10)
            {
                resto = temp % 10;
                temp = temp / 10;
                totalNomeB += resto;
            }
            totalNomeB += temp;
        }
        if(totalNomeA < totalNomeB)
        {
            porcentagem = ((float)totalNomeA * 100) / (float)totalNomeB;
        }
        else
            porcentagem = ((float)totalNomeB * 100) / (float)totalNomeA;
        cout << fixed;
        cout.precision(2);
        cout << porcentagem << " %\n";
    }
}