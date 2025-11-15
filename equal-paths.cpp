#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here


bool equalPaths(Node * root)
{
    // Add your code below
  if(root == NULL)
  {
    return true;
  }

  int leafDepth = -1;
  return helper(root, 0, leafDepth);
}

bool helper(Node* currNode, int depth, int& leafDepth)
{
  //true if tree is empty
  if(currNode == NULL)
  {
    return true;
  }

  if(currNode->left == NULL && currNode->right == NULL)
  {
    if(leafDepth == -1)
    {
      //set the leaf depth
      leafDepth = depth;
      return true;
    }
    //compare depth
    return(depth == leafDepth);
  }

  //recursive call to check the following trees 
  return(helper(currNode->left, depth+1, leafDepth) && helper(currNode->right, depth+1, leafDepth));
}

