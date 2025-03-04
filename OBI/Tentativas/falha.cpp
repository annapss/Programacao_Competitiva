//OBI 2021 - Fase 3 - Nivel 2
//Runtime Error
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string senhas[2002], escolha;
    long long n, total = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> senhas[i];
    }
    for(int i = 1; i < n; i++)
    {
        escolha = senhas[i];
        for(int j = i - 1; j >= 0; j--)
        {
            //cout << "D: " << escolha << " " << senhas[j] << '\n';
            if(senhas[j].find(escolha) == 0)
            {
                total++;
                //cout << "S: " << senhas[j] << " E: " << escolha << '\n';
            } 
            if(escolha.find(senhas[j]) == 0)
            {
                total++;
                //cout << "E: " << escolha << " S: " << senhas[j] << '\n';
            } 
        }
    }
    cout << total << '\n';
}