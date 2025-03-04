//https://neps.academy/br/exercise/398
#include <bits/stdc++.h>
using namespace std;
string palavra;
char letra;
int nLetras = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin >> palavra;
    //cin.ignore(1);
    cin >> letra;
    for(int i = 0; i < palavra.size(); i++)
    {
        if(palavra[i] == letra) nLetras++;
    }
    cout << nLetras;
}