//https://open.kattis.com/problems/lostlineup
#include <iostream>
using namespace std;

pair<int,int> valores[101];
int main()
{
    ios::sync_with_stdio(false);
    int n, qtd_pessoas;
    cin >> n;
    valores[0] = {-1, 1};
    for(int i = 1; i < n; i++)
    {
        cin >> qtd_pessoas;
        valores[i] = {qtd_pessoas, i + 1};
    }
    sort(valores, valores + n);
    cout << "1";
    for(int i = 1; i < n; i++)
    {
        cout << " " << valores[i].second;
    } 
    cout << '\n';
}