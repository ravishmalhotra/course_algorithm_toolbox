#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int cur_num=n;
  int i=1;


  //While loop that meets all the criteria
  //Essentially, as long as the cur_num>2*(current_summand)
  //we know, that the number wont repeat itself. If we do assume
  //that cur_num<2*current_summand, then cur_num will be broken into
  //summands that have already been accounted for, which will
  // lead to repeated numbers, breaking the premise of the problem
  //For example, 100 can be broken down 100-(1+2+....+12)=22. The number
  //22 will be broken down into 13+9.
  //Essentially, the next greater number i.e. 13 + a number <(22/2), a
  // number which will always be less than 13, leading to a repeat.
  //If you notice, this trend will continue to 104.
  //For 105: 105-(1+2+..12)=27=13+a number >27/2 (in this case 14) and thus meets
  // the criteria of non-repetion.


  while ((cur_num>(2*i))) {

  summands.push_back(i);
  cur_num=cur_num-i;
  i=i+1;

  }

  summands.push_back(cur_num);

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
