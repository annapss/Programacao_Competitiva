//https://neps.academy/br/exercise/235
#include <bits/stdc++.h>
using namespace std;
map<char, char> telefone;
char letra = 'A', num2 = '2', novo;
string numero;
int main()
{
    ios::sync_with_stdio(false);
    for(int i = 2; i <= 9; i++)
    {
        if(i != 7 && i != 9)
        {
            telefone.insert({letra, num2});
            letra++;
            telefone.insert({letra,num2});
            letra++;
            telefone.insert({letra, num2});
        }
        else
        {
            telefone.insert({letra, num2});
            letra++;
            telefone.insert({letra, num2});
            letra++;
            telefone.insert({letra, num2});
            letra++;
            telefone.insert({letra, num2});
        }
        letra++;   
        num2++;     
    }
    /*for(auto it = telefone.begin(); it != telefone.end(); it++)
    {
        cout << it -> first << ": " << it -> second << '\n';
    }*/
    getline(cin, numero);
    for(int i = 0; i < numero.size(); i++)
    {
        if(numero[i] >= 65 && numero[i] <= 90)
        {
            novo = telefone[numero[i]];
            numero[i] = novo;
        }
    }
    for(int i = 0; i < numero.size(); i++)
    {
        cout << numero[i];
    }
    cout << '\n';
}