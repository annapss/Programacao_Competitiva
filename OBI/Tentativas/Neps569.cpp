//https://neps.academy/br/exercise/569
//WA - 0
#include <bits/stdc++.h>
#define MAX 503
using namespace std;
int nTerminais, origem, destino, nLinhas, distancia[MAX], lugares, aux, vertA, linha[MAX];
bool visitado[MAX];
vector<int> grafo[MAX];
void bfs(int inicio)
{
    int pai, vertice;
    queue<pair<int, int>> fila;
    fila.push({inicio, 0});
    while(!fila.empty())
    {
        vertice = fila.front().first;
        pai = fila.front().second;
        fila.pop();
        if(visitado[vertice]) continue;
        visitado[vertice] = true;
        if(vertice == inicio) distancia[vertice] = 0;
        else
        {
            if(linha[vertice] != linha[pai])
            {
                distancia[vertice] = distancia[pai] + 1;
            }
        }
        for(int i : grafo[vertice])
        {
            if(!visitado[i])
            {
                fila.push({i, vertice});
            }
        }        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> nTerminais >> nLinhas >> origem >> destino;
    for(int i = 1; i <= nLinhas; i++)
    {
        cin >> lugares;
        for(int j = 0; j < lugares; j++)
        {
            cin >> vertA;
            linha[vertA] = i;
            if(j == 0)
            {
                aux = vertA;
            }
            else
            {
                grafo[vertA].push_back(aux);
                grafo[aux].push_back(vertA);
                aux = vertA;
            }
        }
    }
    bfs(origem);
    for(int i = 1; i <= nTerminais; i++)
    {
        cout << linha[i] << " ";
    }
    cout << '\n';
    //cout << distancia[destino] << '\n';
}