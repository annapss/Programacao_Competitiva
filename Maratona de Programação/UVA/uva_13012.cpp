#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, palpite, resp;
	while(cin >> t)
	{
		resp = 0;
		for(int i = 0; i < 5; i++)
		{
			cin >> palpite;
			if(palpite == t)
				resp++;
		}
		cout << resp << '\n';
	}
}