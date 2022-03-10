//https://neps.academy/br/exercise/1487
#include <bits/stdc++.h>
using namespace std;
bool ehvogal(char letra)
{
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    string palavra, vogais = "uoiea";
    char letra;
    int dist, menor = 100;
    getline(cin, palavra);
    for(int i = 0; i < palavra.size(); i++)
    {
        if(ehvogal(palavra[i])) cout << palavra[i];
        else
        {
            menor = 100;
            cout << palavra[i];
            for(int j = 0; j < vogais.size(); j++)
            {
                dist = abs(palavra[i] - vogais[j]);
                if(dist <= menor) menor = dist, letra = vogais[j];
            }
            cout << letra;
            if(palavra[i] == 'z' || palavra[i] == 'x') cout << 'z';
            else if(palavra[i] == 'v') cout << 'x';
            else
            {
                palavra[i]++;
                letra = palavra[i];
                while(ehvogal(letra))
                {
                    letra++;
                }
                cout << letra;
            }
        }
    }
    cout << '\n';
}
/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    string palavra, pedaco, vogais = "aeiou", cifra;
    int dist;
    char consoante, letra;
    vector<pair<int,char>> distVogais;
    getline(cin, palavra);
    for(int i = 0; i < palavra.size(); i++)
    {
        if(palavra[i] != 'a' && palavra[i] != 'e' && palavra[i] != 'i' && palavra[i] != 'o' && palavra[i] != 'u')
        {
            cout << palavra[i] << '\n';
            pedaco += palavra[i];
            for(int j = 0; j < vogais.size(); j++)
            {  
                letra = vogais[j];          
                dist = abs(palavra[i] - letra);
                distVogais.push_back({dist, vogais[j]});
            }
            sort(distVogais.begin(), distVogais.end());
            for(int j = 0; j < distVogais.size(); j++)
            {
                cout << distVogais[j].first << " " << distVogais[j].second << '\n';
            }
            cout << '\n';
            if(distVogais[0].first == distVogais[1].first)
            {
                if(distVogais[0].second < distVogais[1].second)
                    pedaco += distVogais[0].second;
                else
                    pedaco += distVogais[1].second;
            }
            else
                pedaco += distVogais[0].second;
            if(palavra[i] == 'z')
                pedaco += palavra[i];
            else
            {
                consoante = palavra[i];
                do
                {
                    consoante++;
                } while (consoante == 'a' || consoante == 'e' || consoante == 'i' || consoante == 'o' || consoante == 'u');
                pedaco += consoante;
            }
            //cout << consoante << '\n';
            cifra += pedaco;
            pedaco.erase(0, pedaco.size() - 1);
            vogais.clear();
        }
        else cifra += palavra[i];
    }
    cout << cifra << '\n';
}*/