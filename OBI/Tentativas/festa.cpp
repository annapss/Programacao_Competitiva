//https://neps.academy/br/exercise/1770
//OBI 2021 - Fase 3 - Nivel 2
//Runtime Error - 25
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int fila[400000];
    long long n, m, t, seq = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        fila[i] = i + 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> t;
        for(int j = 0; j < n; j++)
        {
            if(fila[j] != -1)
            {
                seq++;
                if(seq % t == 0)
                {
                    //cout << fila[j] << " ";
                    fila[j] = -1;
                }
            }
        }
        //cout << '\n';
        seq = 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(fila[i] != -1)
        {
            cout << fila[i] << '\n';
        }
    }
}