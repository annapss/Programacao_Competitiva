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
        ano = 1; 
        total_tartarugas_nativas = 0;
        total_tartarugas_imigrantes = 0;
        do
        {
            cin >> total_tartarugas;
            if(total_tartarugas != 0)
            {
                if(ano == 1)
                    total_tartarugas_nativas = total_tartarugas;
                else
                {
                    if(total_tartarugas > (total_tartarugas_imigrantes + total_tartarugas_nativas) * 2)
                    {
                        total_tartarugas_nativas = (total_tartarugas_imigrantes + total_tartarugas_nativas) * 2;
                        total_tartarugas_imigrantes += total_tartarugas - total_tartarugas_nativas;
                    }
                    else
                    {
                        total_tartarugas_nativas = total_tartarugas;
                    }
                }
            }
            ano++; 
        } while(total_tartarugas != 0);
        cout << total_tartarugas_imigrantes << '\n';
    }
}