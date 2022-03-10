//https://neps.academy/br/exercise/824
#include <bits/stdc++.h>
using namespace std;
//Esse aqui ta bem melhor que a primeira versão! :)
bool infectados[1002], temAlguem;
int main()
{
    ios::sync_with_stdio(false);
    int nAmigos, nPessoas, nReunioes, infectado, inicio, reuniao[1002], total = 0;
    cin >> nAmigos >> nReunioes;
    cin >> infectado >> inicio;
    for(int i = 1; i <= nReunioes; i++)
    {
        cin >> nPessoas;
        if(inicio == i) infectados[infectado] = true;
        for(int j = 1; j <= nPessoas; j++)
        {
            cin >> reuniao[j];
            if(infectados[reuniao[j]]) temAlguem = true;
        }
        if(temAlguem)
        {
            for(int j = 1; j <= nPessoas; j++)
            {
                infectados[reuniao[j]] = true;
            }
        }
        temAlguem = false;
    }
    for(int i = 1; i <= nAmigos; i++)
    {
        if(infectados[i]) total++;
    }
    cout << total << '\n';
}