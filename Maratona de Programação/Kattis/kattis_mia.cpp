#include <iostream>
using namespace std;

bool ehMaior(int a, int b)
{
	if((a == 2 && b == 1) || (a == 1 && b == 2))
		return true;
	return false;
}

int ordenaAlg(int a, int b)
{
	return max(a,b) * 10 + min(a,b);
}

int main()
{
	ios::sync_with_stdio(false);
	int s0, s1, r0, r1;
	do
	{
		cin >> s0 >> s1 >> r0 >> r1;
		if(s0 != 0 && s1 != 0 && r0 != 0 && r1 != 0)
		{
			if(ehMaior(s0, s1) && ehMaior(r0, r1))
				cout << "Tie.\n";
			else if(ehMaior(s0, s1) && !ehMaior(r0, r1))
				cout << "Player 1 wins.\n";
			else if(!ehMaior(s0, s1) && ehMaior(r0, r1))
				cout << "Player 2 wins.\n";
			else if(s0 == s1 && s0 <= 6 && r0 != r1)
				cout << "Player 1 wins.\n";
			else if(s0 != s1 && r0 == r1 && r0 <= 6)
				cout << "Player 2 wins.\n";
			else if(ordenaAlg(s0, s1) > ordenaAlg(r0, r1))
				cout << "Player 1 wins.\n";
			else if(ordenaAlg(s0, s1) < ordenaAlg(r0, r1))
				cout << "Player 2 wins.\n";
			else
			 	cout << "Tie.\n";;
		}
	}while(s0 != 0 && s1 != 0 && r0 != 0 && r1 != 0);
}