//https://neps.academy/br/exercise/290
#include <bits/stdc++.h>
using namespace std;
int nAeroportos, nArestas, aeroportoA, aeroportoB, testes, maior;
vector<int> grafo[101];
set<int> congestionado;
int main()
{
    ios::sync_with_stdio(false);
    do
    {
        cin >> nAeroportos >> nArestas;
        if(nAeroportos != 0 && nArestas != 0)
        {
            testes++;
            for(int i = 0; i < nArestas; i++)
            {
                cin >> aeroportoA >> aeroportoB;
                grafo[aeroportoA].push_back(aeroportoB);
                grafo[aeroportoB].push_back(aeroportoA);
            }
            for(int i = 1; i <= nAeroportos; i++)
            {
                if(grafo[i].size() > maior)
                    maior = grafo[i].size();
            }
            for(int i = 1; i <= nAeroportos; i++)
            {
                if(grafo[i].size() == maior)
                    congestionado.insert(i);
            }
            cout << "Teste " << testes << '\n';
            cout << *congestionado.begin();
            if(congestionado.size() != 1)
            {
                congestionado.erase(*congestionado.begin());
                for(auto it = congestionado.begin(); it != congestionado.end(); it++)
                {
                    cout << " " << *it;
                }
            }
            cout << '\n' << '\n';
            congestionado.clear();
            for(int i = 1; i <= nAeroportos; i++)
            {
                grafo[i].clear();
            }
        }
        else break;
    } while (true);
}