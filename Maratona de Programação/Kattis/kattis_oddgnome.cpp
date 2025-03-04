#include <iostream>
#define MAX 1000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t, n, valor[MAX];
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 1; j <= n; j++)
        {
            cin >> valor[j];
        }
        for(int j = 1; j <= n; j++)
        {
            if(j != 1 && j != n)
            {
                if(valor[j] != valor[j - 1] + 1)
                {
                    cout << j << '\n';
                    break;
                }

            }
        }
    }
}