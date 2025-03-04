#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    double x, y;
    cin >> x >> y;
    if(x == 0)
        cout << "ALL GOOD\n";
    else if(y == 1)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << fixed;
        cout.precision(7);
        cout << ((-1) * x) / (y - 1) << '\n';
    }
}