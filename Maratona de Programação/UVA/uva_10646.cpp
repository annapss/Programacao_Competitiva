#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string cartas[53];
	int n;
	cin >> n;
	for(int t = 1; t <= n; t++)
	{
		int y = 0;
		stack<int> pilha;
		for(int i = 1; i <= 52; i++)
		{
			cin >> cartas[i];
			if(i <= 27)
				pilha.push(i);
		}
		for(int i = 1; i <= 3; i++)
		{
			int topo = pilha.top(), x;
			string carta_topo = cartas[topo];
			//cout << carta_topo << '\n';
			if(carta_topo[0] >= '2' && carta_topo[0] <= '9')
				x = carta_topo[0] - '0';
			else
				x = 10;
			//cout << "x: " << x << '\n';
			y += x;
			pilha.pop();
			for(int j = 1; j <= 10 - x; j++)
				pilha.pop();
		}
		//cout << pilha.size() << '\n';
		for(int i = 28; i <= 52; i++)
			pilha.push(i);
		int tamanho = pilha.size();
		for(int i = 1; i <= (tamanho - y); i++)
		{
			//cout << cartas[pilha.top()] << " ";
			pilha.pop();
		}

		cout << "Case " << t << ": " << cartas[pilha.top()] << '\n';
	}
}