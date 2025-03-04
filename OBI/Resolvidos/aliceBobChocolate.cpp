//https://codeforces.com/problemset/problem/6/C
#include <iostream>
#include <vector>
using namespace std;
int tempo, inicioA, inicioB, chocolatesA, chocolatesB, excluidos;
int main()
{
    ios::sync_with_stdio(false);
    int nChocolates;
    cin >> nChocolates;
    int a = 0, b = nChocolates - 1;
    vector<int> chocolates(nChocolates);
    for(int i = 0; i < nChocolates; i++)
    {
        cin >> chocolates[i];
    }
    while(excluidos != nChocolates)
    {
        tempo++;
        if(chocolates[a] == tempo - inicioA)
        {
            inicioA = tempo;
            chocolates[a] = -1;
			excluidos++;
			a++;
            chocolatesA++;
        }
        if(chocolates[b] == tempo - inicioB)
        {
            inicioB = tempo;
			chocolates[b] = -1;
			excluidos++;
			b--;
            chocolatesB++;
        }
		if(b == a && inicioA == inicioB)
        {
            chocolatesA++;
            break;
        }
    }
    cout << chocolatesA << " " << chocolatesB << '\n';
}