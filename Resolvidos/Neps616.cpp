//https://neps.academy/br/exercise/616
#include <iostream>
#define MAX 253
int linhas, colunas;
char mapa[MAX][MAX];
bool visitado[MAX][MAX], bloqueado[MAX][MAX];
const int dirI[] = {+1, -1, +0, +0};
const int dirJ[] = {+0, +0, +1, -1};
const int nDirecoes = 4;
int ovelhas, lobos, totalOvelhas, totalLobos;
bool valido(int i, int j)
{
    if(i < 0 || i >= linhas || j < 0 || j >= colunas) return false;
    else if(visitado[i][j] || bloqueado[i][j]) return false;
    else return true;
}
void dfs(int i, int j)
{
    int proxI, proxJ;
    visitado[i][j] = true;
    if(mapa[i][j] == 'k')
    {
        mapa[i][j] = '.';
        ovelhas++;
    }
    if(mapa[i][j] == 'v') 
    {
        mapa[i][j] = '.';
        lobos++;
    }
    for(int k = 0; k < nDirecoes; k++)
    {
        proxI = i + dirI[k];
        proxJ = j + dirJ[k];
        if(valido(proxI, proxJ))
        {
            dfs(proxI, proxJ);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> linhas >> colunas;
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            std::cin >> mapa[i][j];
            if(mapa[i][j] == '#') bloqueado[i][j] = true;
        }
    }
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            if(valido(i, j))
            {
                if(mapa[i][j] != '#')
                {
                    dfs(i, j);
                    if(lobos >= ovelhas) ovelhas = 0;
                    if(ovelhas > lobos) lobos = 0;
                    totalLobos += lobos;
                    totalOvelhas += ovelhas;
                    lobos = 0;
                    ovelhas = 0;
                }
            }
        }
    }
    std::cout << totalOvelhas << " " << totalLobos << '\n';
}