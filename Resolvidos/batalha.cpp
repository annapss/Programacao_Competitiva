//https://neps.academy/br/exercise/362
#include <bits/stdc++.h>
using namespace std;
long long ataqueA, defesaA, ataqueB, defesaB;
int main()
{
    ios::sync_with_stdio(false);
    cin >> ataqueA >> defesaA >> ataqueB >> defesaB;
    if(ataqueA != defesaB && ataqueB == defesaA)
    {
        cout << 1 << '\n';
    }
    else if(ataqueA == defesaB && ataqueB != defesaA)
    {
        cout << 2 << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}