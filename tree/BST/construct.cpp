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




void preOrderTraveal(Node *root){
    if(root != NULL){
      cout << root->data << " ";
      preOrderTraveal(root->left);
      preOrderTraveal(root->right);
    }
}

Node * construct_bst(int preorder[], int *preorderIndex, int min, int max, int n){
  
    if(*preorderIndex >= n){
        return NULL;
    }
   
    Node *root = NULL;
    
    if(preorder[*preorderIndex] > min && preorder[*preorderIndex] < max){
        root = new Node(preorder[*preorderIndex]);
        *preorderIndex = *preorderIndex + 1;

        if(*preorderIndex < n){
           root->left = construct_bst(preorder, preorderIndex, min, preorder[*preorderIndex-1], n);
        }

        if(*preorderIndex < n){
           root->right = construct_bst(preorder, preorderIndex, preorder[*preorderIndex-1],max, n);
        }
    }
    
    return root;

}

bool isValidBST(Node *root, Node *min = NULL, Node *max = NULL){
    if(root == NULL) {
      return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isValidBST(root->left, min, root);
    bool rightValid = isValidBST(root->right, root, max);

    return leftValid && rightValid;
}



int main(){
    int preorder[] = {10,2,1,13,11};
    int preorderIndex = 0;
    int n  = sizeof(preorder)/sizeof(preorder[0]);
 
    Node *root = construct_bst(preorder, &preorderIndex, INT_MIN, INT_MAX, n);

    //preOrderTraveal(root);

    if(isValidBST(root, NULL, NULL)){
        cout << "Tree is valid";
    } else{
        cout << "Tree is not valid";
    }

    return 0;
}