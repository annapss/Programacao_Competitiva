//https://neps.academy/br/exercise/246
#include <bits/stdc++.h>
using namespace std;
vector<int> bonecas, ordenado, mudancas;
int nBonecas;
int main()
{
    ios::sync_with_stdio(false);
    cin >> nBonecas;
    bonecas.resize(nBonecas);
    ordenado.resize(nBonecas);
    for(int i = 0; i < nBonecas; i++)
    {
        cin >> bonecas[i];
        ordenado[i] = bonecas[i];
    }
    sort(ordenado.begin(), ordenado.end());
    for(int i = 0; i < nBonecas; i++)
    {
        if(bonecas[i] != ordenado[i])
        {
            mudancas.push_back(bonecas[i]);
        }
    }
    sort(mudancas.begin(), mudancas.end());
    cout << mudancas.size() << '\n';
    if(mudancas.size() != 0)
    {
        cout << mudancas[0];
        for(int i = 1; i < mudancas.size(); i++)
        {
            cout << " " << mudancas[i]; 
        }
        cout << '\n';
    }
}