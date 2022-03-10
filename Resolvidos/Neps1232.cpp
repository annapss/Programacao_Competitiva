//https://neps.academy/br/exercise/1232
#include <bits/stdc++.h>
#define MAX 1002
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int montanhas[MAX], nMontanhas, altura, total = 0, maior = 0;
    cin >> nMontanhas >> altura;
    for(int i = 0; i < nMontanhas; i++)
    {
        cin >> montanhas[i];
    }
    int i = 0, j;
    while(i < nMontanhas)
    {
        j = i + 1;
        while(j < nMontanhas && abs(montanhas[j] - montanhas[j - 1]) <= altura) //pra garantir que não vai acessar 
        {                                                                       //um espaço que nao esta alocado
            total++;
            j++;
        }
        if(total + 1 > maior)
            maior = total + 1; // adiciona mais um pra contar a posicao do i
        total = 0;
        i = j;
    }
    cout << maior << '\n';
}