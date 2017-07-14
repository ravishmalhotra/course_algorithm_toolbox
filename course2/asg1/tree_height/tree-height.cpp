#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent; //The child node gets assigned its parent
      parent->children.push_back(this); //The parent node adds this node as its child
    }
};


int main_with_large_stack_space() {
  std::ios_base::sync_with_stdio(0);
  int n;
  std::cin >> n;
  int root_index;
  std::vector<Node> nodes;


  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]); //Assign parent to each number (label). For instance, index 0 gets a parent of node 4.Ex. 5  4 -1 4 1 1


    else
    root_index=child_index;

    nodes[child_index].key = child_index; //Key is the current index
  }

  std::stack<Node> root;
  root.push(nodes[root_index]);
  int height=1;
  int maxheight=0;
  Node *root_current; //Using pointers because we work children pointer variable that needs to be referenced below
  Node *parent_current;
   std::vector <unsigned int> children_done(n);

    while (!(root.empty()))
    {

        root_current=&(root.top());



        if (root_current->children.size()<1 || root_current->children.size()<=children_done[root_current->key]) //If we have reached the leaf node or all the children of the current have been traversed
        {
            root.pop(); //Pop the current node
            maxheight=std::max(height,maxheight); //Find out the max of current height and max height
            height--;//After poping, you are back on the parent, so height reduces by 1

            if (!(root.empty()))
            {

                parent_current=&(root.top()); //Look at the parent of the child that was popped.

                if (parent_current->children.size()>children_done[parent_current->key]) //If total number of children is greater than the children that have been traversed,
                    //Push the next child to the stack and update the children that have been traversed
                {

                    //root.push(*(parent_current->children[0]));
                    root.push(*(parent_current->children[children_done[parent_current->key]]));
                    children_done[parent_current->key]++;
                    height++;


                }

            }

        }

        else //else: children exist and they have not been traversed before
        {
            height++; //Increase the height
            root.push(*(root_current->children[children_done[root_current->key]])); //Push the new children on the stack
            children_done[root_current->key]++; //Increase the number of children that have been traversed



        }

    }



  std::cout << maxheight << std::endl;
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }

#endif
  return main_with_large_stack_space();
}
