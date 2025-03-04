#include <iostream>
#include <cmath>
using namespace std;

long double log(long double base, long double x)
{
    return std::log2(x) / std::log2(base);
}

int main()
{
    ios::sync_with_stdio(false);
    long double testes, populacao, crescimento, comida, resposta;
    long long nova_resposta;
    cin >> testes;
    for(int i = 0; i < testes; i++)
    {
        
        cin >> populacao >> crescimento >> comida;
        if(populacao > comida)
        {
            cout << 0 << '\n';
            continue;
        }
        resposta = log(crescimento, comida/populacao);
        nova_resposta = (int)resposta + 1;
        cout << nova_resposta << '\n';
    }
}