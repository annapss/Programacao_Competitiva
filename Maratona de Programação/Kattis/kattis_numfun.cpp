#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    float a, b, c;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        float menor = min(a, b), maior = max(a, b);
        //cout << maior / menor << '\n';
        if(maior * menor == c || maior + menor == c || maior / menor == c || maior - menor == c)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}