#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node *left, *right;
   Node(int val){
    data = val;
    left = right = NULL;
   }
};


bool isBalanced(Node *root, int *height){
    if(root == NULL){
        return true;
    }
    int lh = 0, rh = 0;
    if(isBalanced(root->left, &lh) == false){
        return false;
    }

    if(isBalanced(root->right, &rh) == false){
        return false;
    }

    *height = max(lh, rh) + 1;

    int diff = lh - rh;

    if(diff >= -1 && diff <= 1){
        return true;
    } else{
        return false;
    }
    
}

Node * buildBalancedTree(int sorted[], int low, int high){
    
    if(low > high){
      return NULL;
    }
    Node *root = NULL;
    
    int mid = (low+high)/2;
    root = new Node(sorted[mid]);
    root->left = buildBalancedTree(sorted, low, mid-1);
    root->right = buildBalancedTree(sorted, mid+1, high);
    
    return root;
}


void displayTree(Node *root){
    if(root != NULL){
        displayTree(root->left);
        cout << root->data << " ";
        displayTree(root->right);
    }
}

/**
 *                          1
 *                      2         3
 *                  4      5    6    7
                 8     9           10
 */
int main(){
    
    int sorted[] = {1,2,3,4,5,6,7,8,9};

    int height = 0;
    
    Node *root = buildBalancedTree(sorted, 0, 8);
    displayTree(root);


    if(isBalanced(root, &height)){
        cout << "Tree is balanced" << endl;
    } else{
        cout << "Tree is not balanced" << endl;
    }

    return 0;
}