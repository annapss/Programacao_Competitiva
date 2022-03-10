//https://www.spoj.com/problems/FARIDA/
#include <bits/stdc++.h>
using namespace std;
long long pdInc[10002], pdExc[10002], testes, nMonstros, monstros[10002];
bool calcInc[10002], calcExc[10002];

long long Incluindo(long long n);
long long Excluindo(long long n);

long long Incluindo(long long n)
{
    if(n == 1) return monstros[n];
    if(calcInc[n]) return pdInc[n];
    calcInc[n] = true;
    pdInc[n] = monstros[n] + Excluindo(n - 1);
    return pdInc[n];
}

long long Excluindo(long long n)
{
    if(n == 1) return 0;
    if(calcExc[n]) return pdExc[n];
    calcExc[n] = true;
    pdExc[n] = max(Excluindo(n - 1), Incluindo(n - 1));
    return pdExc[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> testes;
    for(int i = 1; i <= testes; i++)
    {
        cin >> nMonstros;
        if(nMonstros == 0)
        {
            cout << "Case " << i << ": " << 0 << '\n';
            continue;
        }
        for(int j = 1; j <= nMonstros; j++)
        {
            cin >> monstros[j];
        }
        cout << "Case " << i << ": " << max(Incluindo(nMonstros), Excluindo(nMonstros)) << '\n';
        for(int j = 1; j <= nMonstros; j++)
        {
            calcExc[j] = false;
            calcInc[j] = false;
            pdInc[j] = 0;
            pdExc[j] = 0;
        }
    }
}