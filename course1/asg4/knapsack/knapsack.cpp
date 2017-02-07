#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here

    int length=w.size()+1;
    // Creating a length(w) X W matrix.
    //The idea is to create an optimised solution for each element of a matrix
    // where each row are the different weight options starting from 0 to length(w)
    //each column is the maximum weight of the knapsack from 0 to W

    vector<vector<int>> opt_weight(length, vector <int>(W+1));

    //std::sort(w.begin(), w.end());

    for (int m=0;m<=w.size();m++) {
    opt_weight[m][0]=0;
    }

     for (int m=0;m<=W;m++) {
    opt_weight[0][m]=0;
    }

    int i;
    int j;
    int val;

     for ( j=1; j<=w.size(); j++)
    {

        for (i=1; i<=W;i++)
        {

          opt_weight[j][i]=opt_weight[j-1][i]; //Default weight of current element calculated from previous row

          if (w[j-1]<=i) //Current weight less than total capacity

          {
            val=opt_weight [j-1][i-w[j-1]]+w[j-1]; //val is opt_weight(previous row index,current_weight-weight of the current row).
            //  row j is actually based on w[j-1] due to zero indexing. row 0 is all 0. However w[0] is the first index of specified weight array.

            if (val>opt_weight[j][i]){
            opt_weight[j][i]=val; //Replace the current opt_weight if val> previous opt_weight
            }

          }

        }


    }


    return opt_weight[w.size()][W]; //The final element of the matrix is optimum value


}




int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
