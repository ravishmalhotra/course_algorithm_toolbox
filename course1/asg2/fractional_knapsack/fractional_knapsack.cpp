#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double bag_weight=0.0;

  // write your code here

   vector <double> value_by_weight(weights.size());

  for (int i=0;i<weights.size();i++){
  value_by_weight[i]=((double)values[i]/(double)weights[i]);
  }

  //Sort the value by weight in descending order and return the indices
  vector<int> index(weights.size());
  static int n=0;
  std::generate(index.begin(),index.end(),[&index] {return n++;});

  std::sort(index.begin(), index.end(),[&](int i, int j) {return value_by_weight[i]>value_by_weight[j];});


  //After sorting apply the safe move of using the maximum weight possible of the most valuable item by weight
  for (int i=0;i<weights.size();i++){

  if (capacity==0) {
  return value;
  }


  double current_weight=std::min(capacity,weights[index[i]]);
  bag_weight=bag_weight+current_weight;
  value=value+current_weight*value_by_weight[index[i]];
  capacity=capacity-current_weight;

  }


  return value;
}




int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
