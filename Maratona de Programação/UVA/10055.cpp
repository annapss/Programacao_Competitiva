#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long a, b;

    while(cin >> a >> b)
    {
        cout << abs(b - a) << '\n';
    }
}