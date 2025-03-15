//https://neps.academy/br/exercise/1103
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000003
int pd[MAX], valores[MAX], nValores, somaA, somaB, igual = -1;
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
    cin >> nValores;
    for(int i = 1; i <= nValores; i++)
    {
        cin >> valores[i];
    }
    somaAcumulada(nValores);
    for(int i = 1; i <= nValores; i++)
    {
        somaA = pd[i] - pd[0];
        somaB = pd[nValores] - pd[i];
        //cout << somaA << " " << somaB << '\n';
        if(somaA == somaB) igual = i;
    }
    cout << igual << '\n';
}