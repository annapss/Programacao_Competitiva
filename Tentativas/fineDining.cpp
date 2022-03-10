//http://www.usaco.org/index.php?page=viewproblem2&cpid=861
#include <bits/stdc++.h>
#define INF std::numeric_limits<int>::max()/2
using namespace std;
int nVertices, nArestas, nFenos, verticeA, verticeB, tempo, feno[50002], comida;
int distSemFeno[50002], distComFeno[50002];
bool visitado[50002], fenosVistados[50002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila2;
vector<pair<int, int>> grafo[50002];
void dijkstra(int inicio)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    int vertice, peso, destino;
    for(int i = 1; i <= nVertices; i++)
        distSemFeno[i] = INF;
    distSemFeno[inicio] = 0;
    fila.push({0, inicio});
    while(!fila.empty())
    {
        vertice = fila.top().second;
        fila.pop();
        if(!visitado[vertice])
        {
            visitado[vertice] = true;
            for(auto i : grafo[vertice])
            {
                peso = i.second;
                destino = i.first;
                if(!visitado[destino] && feno[destino] == 0)
                {
                    if(distSemFeno[vertice] + peso < distSemFeno[destino])
                    {
                        distSemFeno[destino] = distSemFeno[vertice] + peso;
                        fila.push({distSemFeno[destino], destino});
                    }
                }
            }
        }
    }
}
void multisource()
{
    int vertice, peso, destino;
    while(!fila2.empty())
    {
        vertice = fila2.top().second;
        fila2.pop();
        if(!visitado[vertice])
        {
            visitado[vertice] = true;
            for(auto i : grafo[vertice])
            {
                peso = distSemFeno[vertice] - feno[vertice];
                destino = i.first;
                if(!visitado[destino])
                {
                    
                }
                /*if(!visitado[destino])
                {
                    //if(distComFeno[vertice] + abs(peso - feno[destino]) < distComFeno[destino])
                    //if(abs(distSemFeno[destino] - distComFeno[vertice] + peso) < feno[vertice])
                    if(!fenosVistados[destino])
                    {
                        if(feno[vertice] != 0)
                        {
                            if(abs(distSemFeno[destino] - (distComFeno[vertice] + peso)) <= feno[vertice])
                            {
                                //if(distComFeno[vertice] + peso < distComFeno[destino])
                                //{
                                    distComFeno[destino] = distComFeno[vertice] + peso;
                                    fila2.push({distComFeno[destino], destino});
                                //}
                            }
                        }
                        else
                        {
                            if(distComFeno[vertice] + peso < distComFeno[destino])
                            {
                                distComFeno[destino] = distComFeno[vertice] + peso;
                                fila2.push({distComFeno[destino], destino});
                            }
                        }
                    }
                }*/
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("dining.in"); // entrada e saida que o usaco pede
    ofstream fout("dining.out"); // se quiser testar, eh so usar cin e cout
    cin >> nVertices >> nArestas >> nFenos;
    for(int i = 0; i < nArestas; i++)
    {
        cin >> verticeA >> verticeB >> tempo;
        grafo[verticeA].push_back({verticeB, tempo});
        grafo[verticeB].push_back({verticeA, tempo});
    }
    for(int i = 0; i < nFenos; i++)
    {
        cin >> verticeA >> comida;
        feno[verticeA] = comida;
        distSemFeno[verticeA] = 0;
        fila2.push({0, verticeA});
        distComFeno[verticeA] = 0;
    }
    dijkstra(nVertices);
    for(int i = 1; i <= nVertices; i++)
    {
        visitado[i] = false;
        if(feno[i] == 0)
            distComFeno[i] = INF;
    }
    multisource();
    for(int i = 1; i < nVertices; i++)
    {
        if(feno[i] != 0)
            cout << 1 << '\n';
        else
        {
            if(distComFeno[i] != INF)
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
    }
}