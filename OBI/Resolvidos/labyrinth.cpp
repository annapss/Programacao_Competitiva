//https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;
char matriz[1001][1001];
int linhas, colunas, inicioI, inicioJ, fimI, fimJ, distancia[1001][1001], difI, difJ;
int dirI[] = {1, -1, 0, 0};
int dirJ[] = {0, 0, 1, -1};
pair<int, int> antecessor[1001][1001];
bool visitado[1001][1001];
bool valido(int i, int j)
{
    if(i < 1 || i > linhas || j < 1 || j > colunas || visitado[i][j] || matriz[i][j] == '#') return false;
    else return true;
}
void bfs(int inicioI, int inicioJ)
{
    queue<pair<int, int>> fila;
    distancia[inicioI][inicioJ] = 0;
    antecessor[inicioI][inicioJ] = {inicioI, inicioJ};
    fila.push({inicioI, inicioJ});
    while(!fila.empty())
    {
        int i = fila.front().first;
        int j = fila.front().second;
        fila.pop();
        if(visitado[i][j]) continue;
        visitado[i][j] = true;
        for(int k = 0; k < 4; k++)
        {
            int proxI = i + dirI[k];
            int proxJ = j + dirJ[k];
            if(valido(proxI, proxJ))
            {
                distancia[proxI][proxJ] = distancia[i][j] + 1;
                antecessor[proxI][proxJ] = {i, j};
                fila.push({proxI, proxJ});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> linhas >> colunas;
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= colunas; j++)
        {
            cin >> matriz[i][j];
            if(matriz[i][j] == 'A')
            {
                inicioI = i;
                inicioJ = j;
            }
            if(matriz[i][j] == 'B')
            {
                fimI = i;
                fimJ = j;
            }
        }
    }
    bfs(fimI, fimJ);
    int aI, aJ;
    int atualI = inicioI, atualJ = inicioJ;
    if(distancia[inicioI][inicioJ] == 0)
        cout << "NO";
    else
    {
        cout << "YES\n";
        cout << distancia[inicioI][inicioJ] << '\n';
        do
        {
            aI = antecessor[atualI][atualJ].first;
            aJ = antecessor[atualI][atualJ].second;
            difI = aI - atualI;
            difJ = aJ - atualJ;
            //cout << atualI << " " << atualJ << ": " << difI << " " << difJ << '\n';
            if(difI == 1 && difJ == 0)
                cout << 'D';
            else if(difI == 0 && difJ == 1)
                cout << 'R';
            else if(difI == -1 && difJ == 0)
                cout << 'U';
            else if(difI == 0 && difJ == -1)
                cout << 'L';
            atualI = aI;
            atualJ = aJ;
        }while(aI != fimI || aJ != fimJ);
    }
    cout << '\n';
}