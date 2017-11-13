#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::vector;
using std::pair;
using std::set;

bool is_unique ( vector <int> &vec) {

   set <int> x(vec.begin(), vec.end());
   if (x.size() == vec.size())
   return 1;

   else
   return 0;

}

void is_cyclic( vector<vector<int> > &adj, vector <int> &explored, int v, bool &cyclic, vector<int> &topo_sort, vector <int> &current_node)
{

    //Function has two cases
    //If a node has no edges, it is a sink
    //Remove the sink and disconnect it from any directed edges
    //Add the node to topo_sort vector

    //Else explore the neighbor and add it to the stack of explored neighbors
    //If the neighbor already exists on the stack of explored neighbors, the graph is cyclic
    //Else apply the recursion function on the neighbor


    if (!explored[v]) {
    current_node.push_back(v);
    explored[v]=1; //Set the specified vertex as explored
    }

    if (adj[v].size() == 0) //Sink found remove it
    {
        topo_sort.push_back(v);
        for (unsigned int j=0; j<adj.size(); j++) //If the last element in any row of the adjaceny matrix is the sink, then remove it
        {
            adj[j].erase(std::remove(adj[j].begin(), adj[j].end(), v), adj[j].end());

        }
       current_node.pop_back(); //Since all connections to this node have been removed, pop it

       if( current_node.size()!=0)
       is_cyclic(adj, explored, current_node.back(), cyclic, topo_sort,current_node); //Apply the recursive function to the top node on the explored node stack

    }


    else
    {
        for ( int i=0; i<adj[v].size(); i++)   //For all the vertices that are connected to this vertex
            {
                    current_node.push_back(adj[v][i]);//Push the neighbor on the explored node stack
                    explored[adj[v][i]]=1;
                    if (!is_unique(current_node)) //Are all the vectors on the stack unique? if not, graph is cyclic
                    {
                        cyclic=1;  //If next element < current element, graph is cyclic
                        return;

                    }

                    else
                        is_cyclic(adj, explored, adj[v][i], cyclic, topo_sort,current_node); //Continue DFS

            }

    }
    return;
}

int acyclic(vector<vector<int> > &adj) {

  //Do DFS to find sink
  //Remove sink
  //If sink cannot be found, graph is cyclic


  bool cyclic=0;
  vector <int> explored(adj.size(),0) ;
  vector<int> topo_sort;
  vector<int> current_node;


  vector<int>::iterator find_zero=std::find(explored.begin(), explored.end(), 0); //Node index that has been unexplored

  while (find_zero != explored.end()) {
  is_cyclic( adj, explored,find_zero-explored.begin(),cyclic, topo_sort, current_node);

  if (cyclic)
  return 1;

  find_zero=std::find(explored.begin(), explored.end(), 0); //Update the index of the first unexplored node

  }

  return 0;


}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
