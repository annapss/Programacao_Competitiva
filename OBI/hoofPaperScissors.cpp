//http://www.usaco.org/index.php?page=viewproblem2&cpid=691
#include <bits/stdc++.h>
#define MAX 100002
using namespace std;
char jogadas[MAX];
int pontuacao, pdH[MAX], pdP[MAX], pdS[MAX], nJogadas, resposta[MAX], posicao, maior;
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("hps.in"); //é só pra poder submeter no usaco
    ofstream fout("hps.out"); //pra testar aqui, eh so trocar por cin e cout
    fin >> nJogadas;
    for(int i = 1; i <= nJogadas; i++)
    {
        fin >> jogadas[i];
    }
    pdH[0] = 0;
    pdS[0] = 0;
    pdP[0] = 0;
    for(int i = 1; i <= nJogadas; i++)
    {
        if(jogadas[i] == 'S')
        {
            pdH[i] = pdH[i - 1] + 1;
            pdS[i] = pdS[i - 1];
            pdP[i] = pdP[i - 1];
        }
        else if(jogadas[i] == 'H')
        {
            pdH[i] = pdH[i - 1];
            pdS[i] = pdS[i - 1];
            pdP[i] = pdP[i - 1] + 1;
        }
        else
        {
            pdH[i] = pdH[i - 1];
            pdS[i] = pdS[i - 1] + 1;
            pdP[i] = pdP[i - 1];
        }
    }
    for(int i = 1; i <= nJogadas; i++)
    {
        //primeiro intervalo
        if(pdH[i] - pdH[0] > pdS[i] - pdS[0] && pdH[i] - pdH[0] > pdP[i] - pdP[0])
            pontuacao += pdH[i] - pdH[0];
        else if(pdS[i] - pdS[0] > pdH[i] - pdH[0] && pdS[i] - pdS[0] > pdP[i] - pdP[0])
            pontuacao += pdS[i] - pdS[0];
        else 
            pontuacao += pdP[i] - pdP[0];
        //segundo intervalo
        if(pdH[nJogadas] - pdH[i] > pdS[nJogadas] - pdS[i] && pdH[nJogadas] - pdH[i] > pdP[nJogadas] - pdP[i])
            pontuacao += pdH[nJogadas] - pdH[i];
        else if(pdS[nJogadas] - pdS[i] > pdH[nJogadas] - pdH[i] && pdS[nJogadas] - pdS[i] > pdP[nJogadas] - pdP[i])
            pontuacao += pdS[nJogadas] - pdS[i];
        else
            pontuacao += pdP[nJogadas] - pdP[i];
        if(pontuacao > maior)
        {
            maior = pontuacao; 
            posicao = i;
        }
        pontuacao = 0;
    }
    fout << maior << '\n';
}