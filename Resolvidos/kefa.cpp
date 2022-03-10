//https://codeforces.com/problemset/problem/580/A
#include <iostream>
#include <limits>
#define INF (std::numeric_limits<int>::max())
using namespace std;
int pd[100002];
int main()
{
    ios::sync_with_stdio(false);
    int nValores, vetor[100001], subvetorMaximo = 0;
    cin >> nValores;
    for(int i = 1; i <= nValores; i++)
    {
        cin >> vetor[i];
    }
    pd[0] = 0;
    vetor[0] = INF;
    for(int i = 1; i <= nValores; i++)
    {
        if(vetor[i - 1] <= vetor[i])
            pd[i] = pd[i - 1] + 1;
        else
            pd[i] = 1;
        if(pd[i] > subvetorMaximo)
        {
            subvetorMaximo = pd[i];
        }
    }
    cout << subvetorMaximo << '\n';
}