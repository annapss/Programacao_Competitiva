//https://neps.academy/br/exercise/54
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    set<int> estoque;
    int n, consulta, fabricados = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> consulta;
        if(estoque.find(consulta) == estoque.end())
        {
            fabricados += 2;
            estoque.insert(consulta);
        }
        else
        {
            estoque.erase(consulta);
        }
    }
    cout << fabricados << '\n';
}