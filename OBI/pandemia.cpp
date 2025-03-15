//https://neps.academy/br/exercise/824
#include <iostream>
#include <set>
#define TAM 1001
int main()
{
    std::ios::sync_with_stdio(false);
    std::set<int> armario;
    bool amigos[TAM] = {};
    int n, m, in, r, a, infectados = 0, numeroa;
    std::cin >> n >> m;
    std::cin >> in >> r;
    amigos[in] = true;
    for(int i = 1; i <= m; i++)
    {
        std::cin >> a;
        for(int j = 1; j <= a; j++)
        {
            std::cin >> numeroa;
            armario.insert(numeroa);
            if(i >= r)
            {
                //Quando tiver no final de cada linha, será checado se tem alguem infectado
                //Se tiver, é marcado true em todos os numeros que estão nessa linha
                if(j == a)
                {
                    for(auto it = armario.begin(); it != armario.end(); it++)
                    {
                        if(amigos[*it] == true)
                        {
                            for(auto t = armario.begin(); t != armario.end(); t++)
                               amigos[*t] = true;
                            break;
                        }
                    }
                    armario.clear();
                }   
            }
            if(j == a)
              armario.clear();
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(amigos[i] == true)
          infectados++;
    }
    std::cout << infectados << '\n';
}