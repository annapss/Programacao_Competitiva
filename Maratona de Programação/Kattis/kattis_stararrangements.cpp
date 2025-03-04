#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	cout << n << ":\n";
	for(long long i = 2; i < n; i++)
	{
		if(n >= i + (i - 1))
		{
			if(n % (i + (i - 1)) == 0 || n % (i + (i - 1)) == i)
				cout << i << "," << i - 1 << '\n';
		}
		if(n >= i * 2)
		{
			if(n % (i * 2) == 0 || n % (i * 2) == i)
				cout << i << "," << i << '\n'; 
		}
	}
}