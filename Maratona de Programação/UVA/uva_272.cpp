#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string frase, resp = "";
	bool aspas = false;
	while(getline(cin,frase))
	{
		resp = "";
		for(int i = 0; i < frase.length(); i++)
		{
			if(frase[i] == '"' && !aspas)
			{
				resp += "``";
				aspas = true;
			}
			else if(frase[i] == '"' && aspas)
			{
				resp += "''";
				aspas = false;
			}
			else {
				resp += frase[i];
			}
		}
		cout << resp << '\n';
	}
}