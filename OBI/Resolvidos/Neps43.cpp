//https://neps.academy/br/exercise/43
#include <bits/stdc++.h>
#define MAX 100001
#define MAXS 400002
using namespace std;
int nAndares, nEventos, andares[MAX], segtree[MAXS], operacao, consulta, novoValor;
void build(int i = 1, int esq = 0, int dir = nAndares - 1)
{
    int meio, fEsq, fDir;
    if(esq == dir)
    {
        segtree[i] = andares[esq];        
    }
    else
    {
        meio = (esq + dir) / 2;
        fEsq = 2 * i;
        fDir = (2 * i) + 1;
        build(fEsq, esq, meio);
        build(fDir, meio + 1, dir);
        segtree[i] = segtree[fEsq] + segtree[fDir];
    }
}
void update(int pos, int valor, int i = 1, int esq = 0, int dir = nAndares - 1)
{
    int meio, fEsq, fDir;
    if(esq == dir)
    {
        segtree[i] = valor;
        andares[pos] = valor;
    }
    else
    {
        meio = (esq + dir) / 2;
        fEsq = 2 * i;
        fDir = (2 * i) + 1;
        if(pos <= meio)
            update(pos, valor, fEsq, esq, meio);
        else
            update(pos, valor, fDir, meio + 1, dir);
        segtree[i] = segtree[fEsq] + segtree[fDir];
    }
}
int query(int cIni, int cFim, int i = 1, int esq = 0, int dir = nAndares - 1)
{
    if(esq > cFim || dir < cIni)
        return 0;
    if(esq >= cIni && dir <= cFim)
        return segtree[i];
    int meio = (esq + dir) / 2;
    int fEsq = 2 * i;
    int fDir = (2 * i) + 1;
    return query(cIni, cFim, fEsq, esq, meio) +
        query(cIni, cFim, fDir, meio + 1, dir);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> nAndares >> nEventos;
    for(int i = 0; i < nAndares; i++)
    {
        cin >> andares[i];
    }
    build();
    for(int i = 0; i < nEventos; i++)
    {
        cin >> operacao >> consulta;
        if(operacao == 1)
        {
           cout << query(0, consulta - 1) << '\n';
        }
        else
        {
            cin >> novoValor;
            update(consulta - 1, novoValor);
        }
    }
}