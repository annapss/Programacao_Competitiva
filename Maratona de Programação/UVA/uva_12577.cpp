#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string texto;
	int cont = 1;
	do
	{
		cin >> texto;
		if(texto != "*")
		{
			cout << "Case " << cont << ": ";
			if(texto == "Hajj")
				cout << "Hajj-e-Akbar\n";
			else
				cout << "Hajj-e-Asghar\n";
			cont++;
		}
	}
	while(texto != "*");
}