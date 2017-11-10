#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;



void explore( vector<vector<int> > &adj, vector <int> &discovered, vector <int> &explored,int v)
{



    explored[v]=1; //Set the specified vertex as explored
    discovered.push_back(v); //Add the the vertex # to discovered

     for (unsigned int i=0; i<adj[v].size(); i++) //For all the vertices that are connected to this vertex

    {

       if (explored[adj[v][i]] != 1) //If the next connected vertex has not been explored


        {

            explore(adj, discovered, explored, adj[v][i]); //Explore it using the recursive function

        }
    }
    return;

}

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here

  //All vertices are marked unexplored
  //For every unexplored vertex, explore and mark explored
  vector <int> discovered;
  vector <int> explored(adj.size(),0) ;

  explore(adj, discovered, explored, x);

  //The discovered vector has all the nodes that are connected. If x and y are in the discover vector, then they must be connected
  std::vector <int>::iterator find_x= std::find(discovered.begin(), discovered.end(), x);
  std::vector <int>::iterator find_y= std::find(discovered.begin(), discovered.end(), y);

  if (find_x!=discovered.end() && find_y !=discovered.end() )
  return 1;

  else
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>()); //2D adjacency matrix
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1); //For vertex 'x'->neighbor 'y'
    adj[y - 1].push_back(x - 1); //For vertex 'y'->neighbor 'x'
  }



  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
