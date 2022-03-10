//https://neps.academy/br/exercise/1773
//OBI 2021 - Nivel 2 - Fase 3
#include <bits/stdc++.h>
using namespace std;
string a, b;
char numA[100001];
char numB[100001];
int main()
{
    ios::sync_with_stdio(false);
    int zeroA = 0, zeroB = 0, tamanho, nenhum = 0, respA, respB;
    getline(cin, a);
    getline(cin, b);
    if(a.length() != b.length())
    { 
        if(a.length() > b.length())
        {
            tamanho = a.length();
            zeroB = a.length() - b.length();
            for(int i = 0; i < zeroB; i++)
            {
                numB[i] = '0';
            }
        }
        else 
        {
            tamanho = b.length();
            zeroA = b.length() - a.length();
            for(int i = 0; i < zeroA; i++)
            {
                numA[i] = '0';
            }
        }
    }
    else
    {
        tamanho = a.length();
    }
    for(int i = 0; i < tamanho; i++)
    {
        numA[i + zeroA] = a[i];
        //cout << numA[i] << " ";
    }
    //cout << '\n';
    for(int i = 0; i < tamanho; i++)
    {
        numB[i + zeroB] = b[i];
        //cout << numB[i] << " ";
    }
    //cout << '\n';
    string  aR, bR;
    for(int i = 0; i < tamanho; i++)
    {
        if(numA[i] < numB[i])
            numA[i] = '-';
        else if(numA[i] > numB[i])
            numB[i] = '-';
    }
    for(int i = 0; i < tamanho; i++)
    {
        if(numA[i] != '-')
        {
            aR += numA[i];
        }
        else
        {
            nenhum++;
        }
    }
    if(nenhum == tamanho)
    {
        respA = -1;
    }
    else
    {
        respA = stoi(aR);
    }
    nenhum = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(numB[i] != '-')
        {
            bR += numB[i];
        }
        else
        {
            nenhum++;
        }
    }
    if(nenhum == tamanho)
    {
        respB = -1;
    }
    else
    {
        respB = stoi(bR);
    }
    if(respA < respB)
    {
        cout << respA << " " << respB;
    }
    else
    {
        cout << respB << " " << respA; 
    }
    cout << '\n';
}