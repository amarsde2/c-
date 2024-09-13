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



/**
 *                          1
 *                      2         3
 *                  4      5    6    7
                 8     9           10
 */

void flatBinaryTree(Node *root){
    if(root == NULL ||  (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->left != NULL){
        flatBinaryTree(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }
    flatBinaryTree(root->right);
}

void displayTree(Node *root){
    if(root == NULL){
        return ;
    }
    if(root != NULL){
        displayTree(root->left);
        cout << " " << root->data << endl;
        displayTree(root->right);
    }
}

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
 
    flatBinaryTree(root);
    displayTree(root);

    return 0;
}