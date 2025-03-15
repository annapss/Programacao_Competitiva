//https://neps.academy/br/exercise/438
#include <bits/stdc++.h>
using namespace std;
vector<int> valores;
int primeiro, nvalores;
int main()
{
    ios::sync_with_stdio(false);
    cin >> nvalores;
    valores.resize(nvalores);
    for(int i = 0; i < nvalores; i++)
    {
        cin >> valores[i];
    }
    primeiro = valores[0];
    sort(valores.begin(), valores.end());
    if(valores[nvalores - 1] == primeiro)
    {
        cout << "S\n";
    }
    else
    {
        cout << "N\n";
    }
}