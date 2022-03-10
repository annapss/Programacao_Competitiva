//https://neps.academy/br/exercise/1018
#include <iostream>
int sobe, desce, muro, altura = 0, dias;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> muro >> sobe >> desce;
    while(altura < muro)
    {
        dias++;
        altura += sobe;
        if(altura < muro) altura -= desce;
    }
    std::cout << dias << '\n';
}