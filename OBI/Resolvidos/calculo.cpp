//OBI 2 fase - Nivel 2 - 2021
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f2/calculo/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int s, soma = 0, algarismo, resposta = 0, a, b;
    cin >> s >> a >> b;
    for(int i = a; i <= b; i++)
    {
        if(i >= 1)
        {
            algarismo = int(i / 1) % 10;
            soma += algarismo;
            if(i >= 10)
            {
                algarismo = int(i / 10) % 10;
                soma += algarismo;
                if(i >= 100)
                {
                    algarismo = int(i / 100) % 10;
                    soma += algarismo;
                    if(i >= 1000) 
                    {
                        algarismo = int(i / 1000) % 10;
                        soma += algarismo;
                        if(i >= 10000)
                        {
                            algarismo = int(i / 10000) % 10;
                            soma += algarismo;
                        }
                    }
                }
            }
        }
        if(soma == s)
            resposta++;
        soma = 0;
    }
    cout << resposta << '\n';
}