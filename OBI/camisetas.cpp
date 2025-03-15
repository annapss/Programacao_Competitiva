//https://neps.academy/br/exercise/980
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, tamanho, medioA = 0, pequenoA = 0, medioB, pequenoB;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tamanho;
        if(tamanho == 1) pequenoA++;
        else medioA++;
    }
    cin >> pequenoB >> medioB;
    if(pequenoA == pequenoB && medioA == medioB) cout << "S\n";
    else cout << "N\n";
}