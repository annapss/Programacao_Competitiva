//https://neps.academy/br/exercise/1479
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    vector<int> idades(3);
    for(int i = 0; i < 3; i++)
        cin >> idades[i];
    sort(idades.begin(), idades.end());
    cout << idades[1] << '\n';
}