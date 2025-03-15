//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2726
//ainda em desenvolvimento
#include <iostream>
#define MAX 22
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int nBancos, nCobrancas, bancoDevedor, bancoCredor, valorDebito, valorTotalBancos[MAX];
    do
    {
        cin >> nBancos >> nCobrancas;
        if(nBancos != 0 && nCobrancas != 0)
        {
            for(int i = 1; i <= nBancos; i++)
            {
                cin >> valorTotalBancos[i];
            }
            for(int i = 0; i < nCobrancas; i++)
            {
                cin >> bancoDevedor >> bancoCredor >> valorDebito;
                valorTotalBancos[bancoDevedor] -= valorDebito;
                valorTotalBancos[bancoCredor] += valorDebito;
            }
            bool resp = true;
            for(int i = 1; i <= nBancos; i++)
            {
                if(valorTotalBancos[i] < 0)
                {
                    cout << "N\n";
                    resp = false;
                }
            }
            if(resp)
                cout << "S\n";
        }
    } while(nBancos != 0 && nCobrancas != 0);
}