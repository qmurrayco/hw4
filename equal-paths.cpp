#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here


bool stepCount(Node* root, int& pathVal, int lvl)
{

	if(root == NULL){
		//stepped one out, go back to leaf
		return true;
	}

	if(!root->left && !root->right){
		if(pathVal < 0){
			//found a leaf, set it equal to the current depth
			pathVal = lvl;
		}

		//if at any point the two arent equal, we know its uneven and will return false
		return (pathVal == lvl);
	}

	return (stepCount(root->left, pathVal, lvl+1) && stepCount(root->right, pathVal, lvl+1));

}

bool equalPaths(Node * root)
{
    //Add your code below
  int pathVal = -1;

	//empty
	if(root == NULL){
		return true;
	}
	
  return (stepCount(root->left, pathVal, 1) && stepCount(root->right, pathVal, 1));
}