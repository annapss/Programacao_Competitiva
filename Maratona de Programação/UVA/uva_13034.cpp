#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int testes, qtd_times;
    bool correto = true;
    cin >> testes;
    for(int i = 0; i < testes; i++)
    {
        correto = true;
        for(int j = 0; j < 13; j++)
        {
            cin >> qtd_times;
            if(qtd_times < 1 || qtd_times > 128)
                correto = false;
        }
        cout << "Set #" << i + 1;
        if(correto)
            cout << ": Yes\n";
        else
            cout << ": No\n";
    }
}