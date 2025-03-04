#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, pontos = 0;
	char dominante;
	string carta;
	map<char, pair<int,int>> descricao;

	descricao.insert({'A', {11, 11}});
	descricao.insert({'K', {4, 4}});
	descricao.insert({'Q', {3, 3}});
	descricao.insert({'J', {20, 2}});
	descricao.insert({'T', {10, 10}});
	descricao.insert({'9', {14, 0}});
	descricao.insert({'8', {0, 0}});
	descricao.insert({'7', {0, 0}});
	cin >> n >> dominante;
	for(int i = 0; i < 4 * n; i++)
	{
		cin >> carta;
		if(carta[1] == dominante)
			pontos += descricao[carta[0]].first;
		else
			pontos += descricao[carta[0]].second;
	}
	cout << pontos << '\n';
}