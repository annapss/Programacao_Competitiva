//http://www.usaco.org/index.php?page=viewproblem2&cpid=644
#include <bits/stdc++.h>
#define MAX 3002
using namespace std;
int nVertices, nArestas, verticeA, verticeB, fechados[MAX], ultimo, verticesVisitados, totalV;
vector<int> grafo[MAX];
bool visitado[MAX], bloqueado[MAX], resposta[MAX];
void dfs(int vertice)
{
    visitado[vertice] = true;
    verticesVisitados++;
    for(int i : grafo[vertice])
    {
        if(!visitado[i] && !bloqueado[i])
            dfs(i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("closing.in"); // entrada e saida que o usaco pede
    ofstream fout("closing.out"); // se quiser testar, eh so usar cin e cout
    fin >> nVertices >> nArestas;
    for(int i = 0; i < nArestas; i++)
    {
        fin >> verticeA >> verticeB;
        grafo[verticeA].push_back(verticeB);
        grafo[verticeB].push_back(verticeA);
    }
    for(int i = 1; i < nVertices; i++)
    {
        fin >> fechados[i];
    }
    fin >> ultimo;
    dfs(ultimo);
	totalV = nVertices;
    if(verticesVisitados == totalV)
        resposta[0] = true;
    else
        resposta[0] = false;
    verticesVisitados = 0;
    for(int i = 1; i <= nVertices; i++)
            visitado[i] = false;
    for(int i = 1; i < nVertices; i++)
    {
        bloqueado[fechados[i]] = true;
		totalV--;
        dfs(ultimo);
		//cout << verticesVisitados << " ";
        if(verticesVisitados == totalV)
            resposta[i] = true;
        else
            resposta[i] = false;
        verticesVisitados = 0;
        for(int j = 1; j <= nVertices; j++)
            visitado[j] = false;
    }
    for(int i = 0; i < nVertices; i++)
    {
		if(resposta[i] == true)
			fout << "YES\n";
		else
			fout << "NO\n";
    }
}