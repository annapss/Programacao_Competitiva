//https://neps.academy/br/exercise/465
#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false);
    int F, M, B, T;
    std::cin >> B >> T;
   if(B == T)
   {
       F = B * 70;
       M = (160 * 70) - F;
       if(F == M)
       {
           std::cout << "0\n";
       }
      else
      {
           if(F > M)
           {
                std::cout << "1\n";
           }
           if(M > F)
           {
                std::cout << "2\n";
           }
      }
   }
   if(B != T)
   {
       F = ((T + B) * 70)/2;
       M = (160 * 70) - F;
       if(F == M)
       {
            std::cout << "0\n";
       }
       else
       {
            if(F > M)
            {
                 std::cout << "1\n";
            }
            if(M > F)
            {
                 std::cout << "2\n";
            }
       }
   }
}