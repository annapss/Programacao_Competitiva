//https://neps.academy/br/exercise/169
#include <iostream>
#define MAX 1001
int main()
{
    std::ios::sync_with_stdio(false);
    int saldo[MAX] = {}, receptores, x, y, v, m, n, total;
    std::cin >> m >> n;
    total = 0;
    receptores = 0;
    for(int i = 0; i < m; i++)
    {
        std::cin >> x >> v >> y;
        saldo[x] -= v;
        saldo[y] += v;
        total += v;
    }
    for(int i = 1; i <= n; i++)
    {
        if(saldo[i] >= 0)
        {
            receptores += saldo[i];
        }
    }
    if(total == receptores)
        std::cout << "N\n" << receptores << '\n';
    else
        std::cout << "S\n" << receptores << '\n';
}