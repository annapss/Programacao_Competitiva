#include <cstdlib>
#include <iostream>
#define MAX 100002
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, custo, valor, lucro[MAX];
	cin >> n >> custo;
	for(int i = 0; i < n; ++i)
	{
		cin >> valor;
		lucro[i] = valor - custo;
	}
	int sum = 0, ans = 0;
	for(int i = 0; i < n; i++)
	{
		sum += lucro[i];
		ans = max(ans, sum);
		if(sum < 0) sum = 0;
	}
	cout << ans << '\n';
}