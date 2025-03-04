#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a, b;
	string a_string, b_string;
	cin >> a_string >> b_string;
	a = stoi(a_string);
	b = stoi(b_string);
	int a_alg = a % 10;
	int b_alg = b % 10;
	a /= 10;
	b /= 10; 
	while(a_alg == b_alg)
	{
		a_alg = a % 10;
		b_alg = b % 10;
		a /= 10;
		b /= 10; 
	}
	if(a_alg > b_alg)
	{
		for(int i = a_string.length() - 1; i >= 0; i--)
			cout << a_string[i];
		cout << '\n';
	}
	else
	{
		for(int i = b_string.length() - 1; i >= 0; i--)
			cout << b_string[i];
		cout << '\n';
	}
}