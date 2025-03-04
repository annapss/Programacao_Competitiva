#include <iostream>
#define MAX 11
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, velocidade, horas[MAX];
	do
	{
		cin >> n;
		if(n != -1)
		{
			int total = 0;
			for(int i = 0; i < n; i++)
			{
				cin >> velocidade >> horas[i];
				if(i == 0)
				{
					total += velocidade * horas[i];
				}
				else {
					total += velocidade * (horas[i] - horas[i - 1]);
				}
			}
			cout << total << " miles\n";
		}
	}while(n != -1);
}