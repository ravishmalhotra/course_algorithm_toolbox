
#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


int gcd_fast(int a, int b)
{


    while (a!=0 && b!=0)
    {

        if (a>b)
        {
            int remainder=a%b;
            a=b;
            b=remainder;

            gcd_fast(a,b);


        }

        else if (a<=b)
        {
            int remainder=b%a;
            b=a;
            a=remainder;
            gcd_fast(a,b);

        }



    }

    if (a!=0)
    return a;

    else
    return b;

}


int main() {
  int a, b;
  std::cin >> a >> b;
 // std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
