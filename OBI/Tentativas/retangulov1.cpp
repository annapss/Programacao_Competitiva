//https://neps.academy/br/exercise/1657
//WA - 20
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    long long nArcos, arcos[100002], retangulos = 0, numeros = 0, soma = 0, j;
    vector<long long> parte1;
    vector<long long> parte2;
    cin >> nArcos;
    for(int i = 1; i <= nArcos; i++)
    {
        cin >> arcos[i];
    }
    for(int i = 1; i <= nArcos / 2; i++)
    {
        parte1.push_back(arcos[i]);
        //cout << parte1[parte1.size() - 1] << " ";
    }
    //cout << '\n';
    for(int i = (nArcos / 2) + 1; i <= nArcos; i++)
    {
        parte2.push_back(arcos[i]);
        //cout << parte2[parte2.size() - 1] << " ";
    }
    //cout << '\n';
    while(parte1.size() != 0 && parte2.size() != 0)
    {
        if(parte1[parte1.size() - 1] == parte2[parte2.size() - 1])
        {
            retangulos++;
            break;
        }
        else
        {
            if(parte1[parte1.size() - 1] < parte2[parte2.size() - 1])
            {
                j = parte1.size() - 1;
                while(soma < parte2[parte2.size() - 1])
                {
                    soma += parte1[j];
                    j--;
                }
                if(soma == parte2[parte2.size() - 1])
                {
                    retangulos++;
                    break;
                }
                else if(soma > parte2[parte2.size() - 1])
                    parte2.pop_back();
            }
            else
            {
                j = parte2.size() - 1;
                while(soma < parte1[parte1.size() - 1])
                {
                    soma += parte2[j];
                    j--;
                }
                if(soma == parte1[parte1.size() - 1])
                {
                    retangulos++;
                    break;
                }
                else if(soma > parte1[parte1.size() - 1])
                    parte1.pop_back();
                
            }
            soma = 0;
        }
    }
    if(retangulos == 0)
        cout << "N\n";
    else
        cout << "S\n";
}