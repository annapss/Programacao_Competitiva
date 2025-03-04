#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int resp;
    if(a == 0 && b == 0)
    {
        cout << "Not a moose\n";
        return 0;
    }

    if(a != b)
        cout << "Odd ";
    else
        cout << "Even ";
    cout <<  max(a,b) * 2 << '\n';
}
