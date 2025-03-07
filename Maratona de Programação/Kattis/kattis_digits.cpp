//https://open.kattis.com/problems/digits
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string valor;
    string qtd_digitos, temp;
    long long cont; 
    do {
        cin >> valor;
        if(valor != "END")
        {
            qtd_digitos = to_string(valor.length());
            temp = valor;
            cont = 1;
            while(qtd_digitos != temp)
            {
                temp = qtd_digitos;
                qtd_digitos = to_string(qtd_digitos.length());
                cont++;
            }
            cout << cont << '\n';
        }
    }while(valor != "END");
}
