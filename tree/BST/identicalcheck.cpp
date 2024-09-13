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
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
  
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(5);
      
    
    if(isIdentical(root ,root1) == true){
        cout << "Identical" << endl;
    } else{
       cout << "Not identical" << endl;
    }
   
    return 0;
}