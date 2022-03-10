#include <bits/stdc++.h>
//OBI 2021 - Fase 3 - Nivel 2
// WA - 90 pontos
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long inicio, fim, cont = 0, numB, total = 0;
    float numA;
    cin >> inicio >> fim;
    for(long long i = inicio; i <= fim; i++)
    {
       numA = sqrt(i);
       numB = int(numA);
       if(numA == numB)
       {
           cont++;
       }
       numA = cbrt(i);
       //cout << numA << " ";
       numB = int(numA);
       if(numA == numB)
       {
           cont++;
       } 
       if(cont == 2)
       {
           total++;
       }
       cont = 0;
    }
    cout << total << '\n';
}