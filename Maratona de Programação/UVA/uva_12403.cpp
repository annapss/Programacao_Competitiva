#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, valor, total = 0;
	string op;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> op;
		if(op == "donate")
		{
			cin >> valor;
			total += valor;
		}
		else {
			cout << total << '\n';
		}
	}
}