// Source: https://usaco.guide/general/io

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int num[3], t;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> num[0] >> num[1] >> num[2];
		sort(num, num + 3);
		cout <<"Case " << i << ": " << num[1] << '\n';
	}
}