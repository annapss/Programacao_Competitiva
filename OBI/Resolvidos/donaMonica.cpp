//https://neps.academy/br/exercise/463
#include <iostream>
#include <algorithm>
int main()
{
    std::ios::sync_with_stdio(false);
    int monica, filho1, filho2, filho3, maior;
    std::cin >> monica >> filho1 >> filho2;
    filho3 = monica - (filho1 + filho2);
    maior = std::max(std::max(filho1,filho2),filho3);
    std::cout << maior << '\n';
}