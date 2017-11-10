#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

void connected_components (vector<vector<int> > &adj, vector<int> &explored, int v)  {

  explored[v]=1;

  for (unsigned int i=0; i<adj[v].size(); i++) {

    if (explored[adj[v][i]] != 1)
    connected_components(adj, explored, adj[v][i]);


  }

  return;
}


int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<int> explored(adj.size(),0);
  //Initialize a list of explored nodes set to zero
  // Starting from node 0, find its connected components
  //Mark the explored neighbor vertices as 1.
  //While the index of explored vertex is not explored.end
  //Find the next set connected components
  //Increment the result of unconnected components by 1

  vector<int>::iterator find_zero=std::find(explored.begin(), explored.end(), 0);

  while ( explored.end() != find_zero) {

  connected_components (adj, explored, find_zero-explored.begin());
  res=res+1;
  find_zero=std::find(explored.begin(), explored.end(), 0);
  }





  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
