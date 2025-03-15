//https://neps.academy/br/exercise/1102
#include <bits/stdc++.h>
using namespace std;
#define MAX 100003
int pd[MAX], valores[MAX], nValores, nIntervalos, inicio, fim;
bool calculado[MAX];
int somaAcumulada(int n)
{
    if(n == 0) return 0; 
    if(calculado[n]) return pd[n];
    calculado[n] = true;
    pd[n] = valores[n] + somaAcumulada(n - 1);
    return pd[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> nValores >> nIntervalos;
    for(int i = 1; i <= nValores; i++)
    {
        cin >> valores[i];
    }
    somaAcumulada(nValores);
    /*for(int i = 1; i <= nValores; i++)
    {
        cout << pd[i] << " ";
    }
    cout << '\n';*/
    for(int i = 0; i < nIntervalos; i++)
    {
        cin >> inicio >> fim;
        cout << pd[fim] - pd[inicio - 1] << '\n';
    }
}