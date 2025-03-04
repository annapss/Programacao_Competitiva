//https://neps.academy/br/exercise/825
#include <iostream>
#define MAX 501
int linhas;
bool JaPassei[MAX][MAX];
char territorio[MAX][MAX], forca;
void trajeto(int l, int c)
{
    if(l < 1 || l > linhas || c < 1 || c > linhas) return;
    if(territorio[l][c] <= forca)
    {
        territorio[l][c] = '*';
        JaPassei[l][c] = true;
        if(territorio[l + 1][c] <= forca && !JaPassei[l + 1][c]) trajeto(l + 1, c);
        if(territorio[l - 1][c] <= forca && !JaPassei[l - 1][c]) trajeto(l - 1, c);
        if(territorio[l][c + 1] <= forca && !JaPassei[l][c + 1]) trajeto(l, c + 1);
        if(territorio[l][c - 1] <= forca && !JaPassei[l][c - 1]) trajeto(l, c - 1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> linhas >> forca;
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= linhas; j++)
        {
            std::cin >> territorio[i][j];
        }
    }
    trajeto(1, 1);
    for(int i = 1; i <= linhas; i++)
    {
        for(int j = 1; j <= linhas; j++)
        {
            std::cout << territorio[i][j];
        }
        std::cout << '\n';
    }
}