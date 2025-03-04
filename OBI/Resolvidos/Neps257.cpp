//https://neps.academy/br/exercise/257
#include <bits/stdc++.h>
using namespace std;
bool calculado[31];
int valor[31];
int fibo(int i)
{
    if(i == 0 || i == 1) return valor[i];
    if(calculado[i]) return valor[i];
    calculado[i] = true;
    valor[i] = fibo(i - 1) + fibo(i - 2);
    return valor[i];
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    valor[1] = 1;
    valor[0] = 1;
    cout << fibo(n) << '\n';
}