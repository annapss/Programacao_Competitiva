#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, qtd_mumble, valor;
	string palavra;
	cin >> n;
	bool resp = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> palavra;
		if(palavra != "mumble")
		{
			valor = stoi(palavra);
			if(valor != i)
				resp = false;
		}
	}
	if(resp)
		cout << "makes sense\n";
	else
		cout << "something is fishy\n";
}