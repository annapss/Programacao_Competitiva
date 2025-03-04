#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, anoAtual, valores[101], total = 0;
	cin >> n >> anoAtual;
	bool resp = false;
	for(int i = 0; i < n; i++)
	{
		cin >> valores[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(valores[i] > anoAtual)
			total++;
		else
		{
			total++;
			resp = true;
			break;
		}
	}
	if(resp == true)
		cout << "It hadn't snowed this early in " << total - 1 << " years!\n";
	else
		cout << "It had never snowed this early!\n";

}