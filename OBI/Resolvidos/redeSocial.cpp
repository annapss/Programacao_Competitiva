//https://neps.academy/br/exercise/1104
#include <bits/stdc++.h>
using namespace std;
long long nPostagens, influencia;
vector<long long> postagens;
int main()
{
    ios::sync_with_stdio(false);
    cin >> nPostagens;
    postagens.resize(nPostagens);
    for(int i = 0; i < postagens.size(); i++)
    {
        cin >> postagens[i];
    }
    sort(postagens.begin(), postagens.end());
    for(int i = postagens.size() - 1; i >= 0; i--)
    {
        influencia++;
        if(postagens[i] < influencia)
        {
            influencia--;
            break;
        }
    }
    cout << influencia << '\n';
}