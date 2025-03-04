//https://atcoder.jp/contests/dp/submit?taskScreenName=dp_b
#include <iostream>
#include <algorithm>
#include <limits>
#define INF (std::numeric_limits<int>::max() / 2)
#define MAXN 100001
bool calculado[MAXN];
int nPedras, passos, pd[MAXN], pedras[MAXN], menor = INF;
int diferencaAcumulada(int n)
{
    if(n == nPedras) return 0;
    if(calculado[n]) return pd[n];
    calculado[n] = true;
    for(int i = 1; i <= passos; i++)
    {
        if(n + i <= nPedras)
        {
            if(std::abs(pedras[n] - pedras[n + i]) + diferencaAcumulada(n + i) < menor)
            {
                menor = std::abs(pedras[n] - pedras[n + i]) + diferencaAcumulada(n + i);
            }
        }
    }
    pd[n] = menor;
    menor = INF;
    return pd[n];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> nPedras >> passos;
    for(int i = 1; i <= nPedras; i++)
    {
        std::cin >> pedras[i];
    }
    diferencaAcumulada(1);
    std::cout << pd[1] << '\n';
} 