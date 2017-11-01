#include <algorithm>
#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::is_sorted;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};



void in_order_recursive( const vector <Node> &tree, int index, vector <int> &result) {

  if (tree[index].left!=-1) {
 in_order_recursive(tree,tree[index].left,result);
 }

 result.push_back(tree[index].key);

  if (tree[index].right!=-1) {
 in_order_recursive(tree,tree[index].right,result);
 }

}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement in-order traversal and check if the array is sorted. If its sorted, BST criteria is met
  //This will take O(n) for in-order traversal and O(n) for checking sorted.

  vector <int> result;


  if (tree.size()>1 ) {
  in_order_recursive(tree,0,result);

  if (is_sorted(result.begin(), result.end()) )
  return true;

  else
  return false;

  }

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  };

  if (IsBinarySearchTree(tree)){
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
