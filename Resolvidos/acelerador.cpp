//OBI 2020 - Nivel 2 - Fase 1
//https://olimpiada.ic.unicamp.br/pratique/p2/2020/f1/acelerador/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long velocidade;
    cin >> velocidade;
    velocidade = velocidade - 3;
    if(velocidade % 8 == 3) cout << 1 << '\n';
    else if(velocidade % 8 == 4) cout << 2 << '\n';
    else cout << 3 << '\n';
}