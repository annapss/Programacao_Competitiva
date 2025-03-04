#include <iostream>
using namespace std;

char grid[201][201];
int l, c;
bool visitado[201][201];
int cont = 0;
int option = 0;
void percurso(int i, int j)
{
	if(i < 0 || i >= l || j < 0 || j >= c)
	{
		option = 3;
		return;
	}
	if(visitado[i][j])
	{
		option = 2;
		return;
	}
	visitado[i][j] = true;
	cont++;
	if(grid[i][j] == 'N')
		percurso(i - 1, j);
	else if(grid[i][j] == 'S')
		percurso(i + 1, j);
	else if(grid[i][j] == 'E')
		percurso(i, j + 1);
	else if(grid[i][j] == 'W')
		percurso(i, j - 1);
	else
	{
		option = 1;
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> l >> c;
	for(int i = 0; i < l; i++)
	{
		for(int j = 0; j < c; j++)
		{
			visitado[i][j] = false;
			cin >> grid[i][j];
		}
	}
	percurso(0,0);
	if(option == 1)
		cout << cont - 1<< '\n';
	else if(option == 2)
	 	cout << "Lost\n";
	else
		cout << "Out\n";

}