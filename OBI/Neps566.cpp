//https://neps.academy/br/exercise/566
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
int preco, nParcelas, resto, valor, i;
int main()
{
    ios::sync_with_stdio(false);
    cin >> preco >> nParcelas;
    resto = preco % nParcelas;
    valor = preco / nParcelas;
    vector<int> parcelas(nParcelas, valor);
    if(resto != 0)
    {
        while(resto--)
        {
            parcelas[i]++;
            i++;
        }
    }
    for(int i = 0; i < parcelas.size(); i++)
    {
        cout << parcelas[i] << '\n';
    }
    cout << '\n';
}