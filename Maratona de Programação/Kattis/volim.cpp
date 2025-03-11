//https://open.kattis.com/problems/volim
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    char resposta;
    int atual, nPerguntas, tempo_total = 0, limite = 210, tempo, explodiu = -1;
    cin >> atual >> nPerguntas;
    for(int i = 0; i < nPerguntas; i++)
    {
        cin >> tempo >> resposta;
        if(explodiu == -1)
        {
            tempo_total += tempo;
            if(tempo_total >= limite)
                explodiu = atual;
            if(resposta == 'T')
            {
                if(atual == 8)
                    atual = 1;
                else
                    atual++;
            }
        }
    }
    cout << explodiu << '\n';
}