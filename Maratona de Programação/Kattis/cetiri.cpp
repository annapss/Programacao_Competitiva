//https://open.kattis.com/problems/cetiri
#include <iostream>
#include <algorithm>
using namespace std;

int valores[3];

int main()
{
    ios::sync_with_stdio(false);
    for(int i = 0; i < 3; i++)
    {
        cin >> valores[i];
    }
    sort(valores, valores + 3);
    if(valores[1] - valores[0] == valores[2] - valores[1])
    {
        cout << valores[2] + (valores[2] - valores[1]) << '\n';
    }
    else
    {
        int difA = valores[1] - valores[0];
        int difB = valores[2] - valores[1];
        if(difA < difB)
        {
            cout << valores[1] + difA;
        }
        else
        {
            cout << valores[0] + difB << '\n';
        }
    }
}