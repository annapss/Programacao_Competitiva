//http://www.usaco.org/index.php?page=viewproblem2&cpid=894
#include <bits/stdc++.h>
#define MAX 100002
using namespace std;
long long grau[MAX];
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin("planting.in"); //pra usar no usaco tem fazer essa merda!
    ofstream fout("planting.out"); //pra compilar na máquina é só usar cin e cout normal
    long long nVertices, verticeA, verticeB, maior = 0;
    fin >> nVertices;
    for(int i = 1; i < nVertices; i++)
    {
        fin >> verticeA >> verticeB;
        grau[verticeA]++;
        grau[verticeB]++;
    }
    for(int i = 1; i <= nVertices; i++)
    {
        if(grau[i] > maior)
        {
            maior = grau[i];
        }
    }
    fout << maior + 1 << '\n';
}