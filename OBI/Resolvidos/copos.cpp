//https://neps.academy/br/exercise/472
#include <bits/stdc++.h>
using namespace std;
char ordem[4], aux, inicio;
int movimentos, tipo;
const char resultado[4] = {'i', 'A', 'B', 'C'};
int main()
{
    ios::sync_with_stdio(false);
    ordem[1] = 'A';
    ordem[2] = 'B';
    ordem[3] = 'C';
    cin >> movimentos >> inicio;
    for(int i = 0; i < movimentos; i++)
    {
        cin >> tipo;
        if(tipo == 1)
        {
            aux = ordem[1];
            ordem[1] = ordem[2];
            ordem[2] = aux;
        }
        else if(tipo == 2)
        {
            aux = ordem[2];
            ordem[2] = ordem[3];
            ordem[3] = aux;
        }
        else
        {
            aux = ordem[1];
            ordem[1] = ordem[3];
            ordem[3] = aux;
        }
    }
    for(int i = 1; i <= 3; i++)
    {
        if(ordem[i] == inicio)
        {
            cout << resultado[i] << '\n';
        }
    }
}