//https://neps.academy/br/exercise/1055
//TFC 2020
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;
long long pd[MAX], nlinhas, dias, preco, nConsultas, comeco, fim, total;
vector<long long> valores;
bool calculado[MAX];
long long somaAcumulada(int i)
{
    if(i == 0) return pd[0];
    if(calculado[i]) return pd[i];
    calculado[i] = true;
    pd[i] = somaAcumulada(i - 1) + valores[i];
    return pd[i]; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> nlinhas;
    for(int i = 0; i < nlinhas; i++)
    {
        cin >>  dias >> preco;
        while(dias--)
        {
            valores.push_back(preco);
        }
    }
    pd[0] = valores[0];
    for(int i = 0; i < valores.size(); i++)
    {
        somaAcumulada(i);
    }
    cin >> nConsultas;
    for(int i = 0; i < nConsultas; i++)
    {
        cin >> comeco >> fim;
        total = (pd[fim - 1] - pd[comeco - 1]) + valores[comeco - 1];
        cout << total << '\n';
    }
}