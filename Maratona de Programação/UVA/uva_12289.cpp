#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string texto, one = "one", two = "two";
	int n;
	cin >> n;
	cin.ignore(1);
	for(int i = 0; i < n; i++)
	{
		cin >> texto;
		if(texto.length() != 3)
		{
			cout << "3\n";
			continue;
		}
		int iguais = 0;
		for(int i = 0; i < 3; i++)
		{
			if(one[i] == texto[i])
				iguais++;
		}
		if(iguais > 1)
			cout << "1\n";
		else
			cout << "2\n";
	} 
}