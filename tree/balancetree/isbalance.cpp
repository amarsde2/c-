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


/**
 *                          1
 *                      2         3
 *                  4      5    6    7
                 8     9           10
 */
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->right->right->left = new Node(10);
    int height = 0;

    if(isBalanced(root, &height)){
        cout << "Tree is balanced" << endl;
    } else{
        cout << "Tree is not balanced" << endl;
    }

    return 0;
}