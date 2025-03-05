//https://open.kattis.com/problems/zanzibar
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long testes, total_tartarugas, ano, total_tartarugas_nativas, total_tartarugas_imigrantes;
    cin >> testes;
    for(int i = 0; i < testes; i++)
    {
        total_tartarugas = 1;
        total_tartarugas_imigrantes = 0;
        do
        {
            total_tartarugas_nativas = total_tartarugas;
            cin >> total_tartarugas;
            if(total_tartarugas != 0)
            {
                if(total_tartarugas > total_tartarugas_nativas * 2)
                {
                    total_tartarugas_imigrantes += total_tartarugas - (total_tartarugas_nativas * 2);
                }
            } 
        } while(total_tartarugas != 0);
        cout << total_tartarugas_imigrantes << '\n';
    }
}