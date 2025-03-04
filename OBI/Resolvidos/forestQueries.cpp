//https://cses.fi/problemset/task/1652
#include <bits/stdc++.h>
using namespace std;

int linhas, colunas, floresta[1001][1001], x, y, x2, y2, pd[1001][1001], resposta;
bool calculado[1001][1001];
char tipo;
int soma2d(int i, int j)
{
    if(i < 1 || i > linhas || j < 1 || j > linhas) return 0;
    if(i == 1 && j == 1) return floresta[i][j];
    if(calculado[i][j]) return pd[i][j];
    calculado[i][j] = true;
    pd[i][j] = soma2d(i - 1, j) + soma2d(i, j - 1) - soma2d(i - 1, j - 1) + floresta[i][j];
    return pd[i][j];
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> linhas >> colunas;
	for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= linhas; j++)
        {
            cin >> tipo;
            if(tipo == '*')
                floresta[i][j] = 1;
            else
                floresta[i][j] = 0;
        }
    }
    for(int i = 1; i <= colunas; i++)
    {
        cin >> y >> x >> y2 >> x2;
        resposta = soma2d(y2, x2) - soma2d(y - 1, x2) - soma2d(y2, x - 1) + soma2d(y - 1, x - 1);
        cout << resposta << '\n';
    }
}