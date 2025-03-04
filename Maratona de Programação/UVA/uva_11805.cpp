#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, k, p, t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        cin >> n >> k >> p;
        if(k + p <= n)
        {
            cout << k + p << '\n';
        }
        else
        {
            if((p % n) + k <= n)
                cout << (p % n) + k << '\n';
            else
                cout << (p % n) - (n - k) << '\n';
        }
        
    }
}