//https://neps.academy/br/exercise/25
//WA - 0
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    int n, d, x, dario, xerxes;
    std::cin >> n;
    xerxes = 0;
    dario = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin >> d >> x;
        if(d + 1 == x || d - 1 == x)
        {
            if(d < x)
              dario++;
            else
              xerxes++;
        }
        if((d == 0 && x == 4) || (d == 4 && x == 0))
        {
            if(d > x)
              dario++;
            else
              xerxes++;
        }
        if((d == 0 && x == 2) || (d == 3 && x == 0) || (d == 1 && x == 3) || (d == 4 && x == 1) || (d == 2 && x == 4))
          dario++;
        else
          xerxes++;
    }
    if(dario > xerxes)
       std::cout << "dario" << '\n';
    else
       std::cout << "xerxes" << '\n';
}