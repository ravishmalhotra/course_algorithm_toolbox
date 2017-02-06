#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> total_step(n+1);
  std::vector<int> predecessor(n+1);
  std::vector<int> sequence {n};


  predecessor[0]=0;
  predecessor[1]=0;
  total_step[0]=0;
  total_step[1]=0;
  int y;

    for (int i=2; i<=n; i++)
    {

      //Creating an optimised solution for each element from 2 to n
      //If n%3=0 then check if n-1 has less number of total steps than n/3
      //If yes, total steps for number 'n' is total_steps(n-1)+1
      //If no, total steps for number 'n' is total_steps (n/3)+1

        if (i%3==0)
        {

            if (total_step[i-1]<total_step[i/3])
            {
                y=i-1;
                total_step[i]=total_step[y]+1;
            }

            else
            {
                y=i/3;
                total_step[i]=total_step[y]+1;

            }
            predecessor[i]=y;

        }

      //If n%2=0 then check if n-1 has less number of total steps than n/2
      //If yes, total steps for number 'n' is total_steps(n-1)+1
      //If no, total steps for number 'n' is total_steps (n/2)+1
      //For ex. 10

        else if (i%2==0)
        {
            if (total_step[i-1]<total_step[i/2])
            {
                y=i-1;
                total_step[i]=total_step[y]+1;
            }

            else
            {
                y=i/2;
                total_step[i]=total_step[y]+1;

            }
            predecessor[i]=y;

        }

        //If not divisible by 2 or 3, subtract 1 from the number

        else
        {
            y=i-1;
            total_step[i]=total_step[y]+1;
            predecessor[i]=y;
        }

    }

//Using the predecessor from n all the way to 1 to figure out the optimal sequence
//For ex. for 10. Predecessor[1]=9,[2]=3 [4]=1
  while (n>1) {


  sequence.push_back(predecessor[n]);
  n=predecessor[n];

  }


  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
