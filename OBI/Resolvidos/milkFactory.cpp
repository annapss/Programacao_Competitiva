//http://www.usaco.org/index.php?page=viewproblem2&cpid=940
#include <iostream>
#include <fstream>
#include <vector>
#define MAX 102
using namespace std;
vector<int> grafo[MAX];
bool visitado[MAX];
int nVertices, verticeA, verticeB, chegada, maior, resposta;
void dfs(int vertice)
{
    visitado[vertice] = true;
    chegada++;
    for(int i : grafo[vertice])
    {
        if(!visitado[i])
            dfs(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("factory.in");
    ofstream fout("factory.out");
    fin >> nVertices;
    for(int i = 1; i < nVertices; i++)
    {
        fin >> verticeA >> verticeB;
        grafo[verticeB].push_back(verticeA);
    }
    for(int i = 1; i <= nVertices; i++)
    {
        dfs(i);
        if(chegada == nVertices)
        { 
            resposta = i;
            break;
        }
        for(int j = 1; j <= nVertices; j++)
            visitado[j] = false;
        chegada = 0;
    }
    if(chegada == nVertices)
        fout << resposta << '\n';
    else
        fout << -1 << '\n';
}