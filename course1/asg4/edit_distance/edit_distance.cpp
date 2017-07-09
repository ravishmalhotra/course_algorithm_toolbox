#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  //write your code here

  vector<vector<int>> opt_edit(str1.size()+1, vector <int> (str2.size()+1,0));
  int m;
  int n;

  for (m=1; m<=str1.size();m++) {
  opt_edit[m][0]=m;

  }

  for (n=1; n<=str2.size();n++) {
  opt_edit[0][n]=n;

  }


  for (m=1;m<=str1.size();m++) {


  for (n=1;n<=str2.size();n++) {


  if (str1[m-1]==str2[n-1])
  opt_edit[m][n]=min(opt_edit[m-1] [n-1], min (opt_edit[m-1][n]+1, opt_edit[m][n-1]+1));

  else
  opt_edit[m][n]=min(opt_edit[m-1] [n-1]+1, min (opt_edit[m-1][n]+1, opt_edit[m][n-1]+1));

  }


  }

  return opt_edit[m-1][n-1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
