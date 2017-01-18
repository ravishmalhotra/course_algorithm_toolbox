#include <iostream>
int get_change(int m)
{
    //write your code here
    int n=0;

          while (m>0)
    {

        if (m>=10)
        {
            m=m-10;
            n++;
        }

        else if (m>=5 && m<10)
        {
            m=m-5;
            n++;

        }

        else if (m>=1 && m<5)
        {
            m=m-1;
            n++;
        }

    }
    return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
