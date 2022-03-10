//https://atcoder.jp/contests/dp/tasks/dp_a
#include <iostream>
#include <algorithm>
#define MAX 100001
int nPedras, pd[MAX], pedras[MAX], distA, distB, total;
bool calculado[MAX];
int diferencaAcumulada(int i)
{
    if(i == nPedras) return 0;
    if(calculado[i]) return pd[i];
    calculado[i] = true;
    if(i == nPedras - 1)
    {
        pd[i] = (std::abs(pedras[i] - pedras[i + 1])) + diferencaAcumulada(i + 1);
    }
    else
    {
        if(std::abs(pedras[i] - pedras[i + 1]) + diferencaAcumulada(i + 1) < std::abs(pedras[i] - pedras[i + 2]) + diferencaAcumulada(i + 2))
        {
            pd[i] = (std::abs(pedras[i] - pedras[i + 1])) + diferencaAcumulada(i + 1);
        }
        else
        {
            pd[i] = (std::abs(pedras[i] - pedras[i + 2])) + diferencaAcumulada(i + 2);
        }
    }
    return pd[i];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> nPedras;
    for(int i = 1; i <= nPedras; i++)
    {
        std::cin >> pedras[i];
    }
    diferencaAcumulada(1);
    std::cout << pd[1] << '\n';
} 