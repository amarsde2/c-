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





Node * BST_INSERT(Node *root, int key){
    if(root == NULL){
        return new Node(key);
    } else if(root->data < key){
        root->right = BST_INSERT(root->right, key);
    } else{
        root->left = BST_INSERT(root->left, key);
    }

    return root;
}

bool isIdentical(Node *root1, Node *root2){
   
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        return root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right); 
    } 
}


/**
 *   1  
 *      2  
 *        5
 *      3   9 
 *        8
 *      7
 */       


struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isbst;
};


Info getLargetBST(Node *root){
     
    Info largbst;
   
    if(root == NULL){
       return {0, INT_MIN, INT_MAX, 0, true};
    }

    if(root->left == NULL && root->right == NULL){
      return {1, root->data, root->data, 1, true};
    }
     
    Info leftbst = getLargetBST(root->left);
    Info rightbst = getLargetBST(root->right);

    Info curr;

    curr.size = (leftbst.size + rightbst.size + 1);

    if(leftbst.isbst && rightbst.isbst && leftbst.max < root->data && rightbst.min > root->data){

       curr.min = min(leftbst.min, min(root->data, rightbst.min));
       curr.max = max(rightbst.max, max(root->data, leftbst.max));
       curr.isbst = true;  
       curr.ans  = curr.size;
       return curr;
    }

    curr.ans = max(leftbst.ans, rightbst.ans);
    curr.isbst = true;
    return curr;

}


int main(){
    Node *root = new Node(15);
    root->left = new Node(20);   
    root->right = new Node(30);   
    root->left->left = new Node(5);
  
    cout << "Larget BST size : " << getLargetBST(root).ans << endl;
     
    return 0;
}