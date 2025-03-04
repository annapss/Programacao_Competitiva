#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, valor, total = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> valor;
		if(valor < 0)
			total += valor * -1;
	}
	cout << total << '\n';
}