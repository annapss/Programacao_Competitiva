//https://neps.academy/br/exercise/1002
//WA - 0
#include <bits/stdc++.h>
using namespace std;
#define MAX 201
vector<int> grafo[MAX];
int salaos, tuneis, salaA, salaB, peso[MAX], inicio, total;
bool visitado[MAX];
void dfs(int vertice)
{
    visitado[vertice] = true;
    for(int i : grafo[vertice])
    {
        if(!visitado[i])
        {
            total++;
            dfs(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> salaos >> tuneis >> inicio;
    for(int i = 1; i <= salaos; i++)
    {
        cin >> peso[i];
    }
    for(int i = 0; i < tuneis; i++)
    {
        cin >> salaA >> salaB;
        if(peso[salaA] < peso[salaB])
        {
            grafo[salaB].push_back(salaA);
        }
        else
        {
            grafo[salaA].push_back(salaB);
        }
    }
    dfs(inicio);
    cout << total - 1 << '\n';
}