#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
    /*int current_weight = 0;
    for (size_t i = 0; i < w.size(); ++i) {
     if (current_weight + w[i] <= W) {
       current_weight += w[i];
     }
    }*/
    vector<int> opt_weight(W+1);

    //std::sort(w.begin(), w.end());

    int i;
    opt_weight[0]=0;

    for (i=1; i<W;i++)
    {

        opt_weight[i]=opt_weight[i-1];

        for (int j=0; j<w.size(); j++)
        {

            for (int k=0; k<i; k++)
            {

                if (w[j]<=[i] && opt_weight[i]<=opt_weight[k]+w[j])
                {
                    opt_weight[i]=opt_weight[k]+w[j];

                }



            }


        }


    }

    return opt_weight[i];
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
