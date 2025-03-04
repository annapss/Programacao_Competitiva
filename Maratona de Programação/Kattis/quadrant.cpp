#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    if(x > 0 && y > 0)
        cout << "1\n";
    else if(x > 0 && y < 0)
        cout << "4\n";
    else if(x < 0 && y < 0)
        cout << "3\n";
    else
        cout << "2\n";
}