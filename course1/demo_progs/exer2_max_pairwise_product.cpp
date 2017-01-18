#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

/*long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((long long) numbers[i] * (long long)numbers[j] > result) {
        result = (long long)numbers[i] * (long long)numbers[j];
      }
    }
  }
  return result;
}
*/

long long MaxPairwiseProduct_faster(const vector<int> &numbers) {

   //long long result=0;
   int n=numbers.size();

   int max_index1=-1;

   for (int i=0;i<n;i++){

   if ((max_index1==-1)||(numbers[i]>numbers[max_index1]))
   max_index1=i;

   }

    int max_index2=-1;

    for (int j=0;j<n;j++) {

    if ((j!=max_index1) && ((max_index2==-1)||((numbers[j]>numbers[max_index2]))))
    max_index2=j;

    }

    return ((long long)numbers[max_index1])*numbers[max_index2];



}


long long MaxPairwiseProductFast(const vector<int>& numbers) {
  int n = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < n; ++i)
    if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
      max_index1 = i;

  int max_index2 = -1;
  for (int j = 0; j < n; ++j)
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
      max_index2 = j;

  return ((long long)(numbers[max_index1])) * numbers[max_index2];
}



int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

   //   long long result1 = MaxPairwiseProduct(numbers);
   //  cout << result1 << "\n";
    long long results=MaxPairwiseProduct_faster(numbers);
    cout<<results<<"\n";
    return 0;
}
