#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a, b, c;
	while(cin >> a >> b >> c)
	{
		if(a + b + c == 0 || a + b + c == 3)
			cout << "*\n";
		else if (a + b + c == 1)
		{
			if(a == 1)
				cout << "A\n";
			else if(b == 1)
				cout << "B\n";
			else
				cout << "C\n";
		}
		else {
			if(a == 0)
				cout << "A\n";
			else if(b == 0)
				cout << "B\n";
			else
				cout << "C\n";
		}

	}
}