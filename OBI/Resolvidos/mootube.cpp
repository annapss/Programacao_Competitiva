//http://www.usaco.org/index.php?page=viewproblem2&cpid=788
#include <bits/stdc++.h>
#define MAX 5002
using namespace std;
long long nVertices, peso, verticeA, verticeB, k, nConsultas, consulta, videos;
bool visitado[MAX];
vector<pair<long long, long long>> grafo[MAX]; 
void dfs(int vertice)
{
    visitado[vertice] = true;
    videos++;
    for(pair<long long, long long> j : grafo[vertice])
    {
        if(!visitado[j.first] && j.second >= k)
        {
            dfs(j.first);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    fin >> nVertices >> nConsultas;
    for(int i = 1; i < nVertices; i++)
    {
        fin >> verticeA >> verticeB >> peso;
        grafo[verticeA].push_back({verticeB, peso});
        grafo[verticeB].push_back({verticeA, peso});
    }
    for(int i = 0; i < nConsultas; i++)
    {
        fin >> k >> consulta;
        dfs(consulta);
        fout << videos - 1 << '\n';
        videos = 0;
        for(int j = 1; j <= nVertices; j++)
        {
            visitado[j] = false;
        }
    }
}