#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int inicio, fim;
	do {
		cin >> inicio >> fim;
		if(inicio != -1 && fim != -1)
		{
			int caminho1, caminho2, caminho3;
			caminho1 = abs(fim - inicio);
			caminho2 = abs(99 - inicio) + 0 + fim + 1;
			caminho3 = abs(inicio - 0) + abs(99 - fim) + 1;
			cout << min(min(caminho1, caminho2), caminho3) << '\n';
		}
	}while (inicio != -1 && fim != -1);
}