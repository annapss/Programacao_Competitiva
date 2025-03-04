#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, maior = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, qtd;
        maior = 0;
        cin >> qtd;
        while(qtd--)
        {
            cin >> a;
            if(a > maior)  
                maior = a;
        }
        cout << "Case " << i + 1 << ": " << maior << '\n';
    }
}