//https://neps.academy/br/exercise/1656
#include <bits/stdc++.h>
#define INF (numeric_limits<int>::max()) / 2
using namespace std;
int main()
{
    long long a, b, c, menor = INF;
    vector<long long> ordem;
    cin >> a >> b;
    c = a * 3 - a - b;
    ordem.push_back(c);
    c = b * 3 - a - b;
    ordem.push_back(c);
    c = (a + b) / 2;
    ordem.push_back(c);
    sort(ordem.begin(), ordem.end());
    cout << ordem[0] << '\n';
}