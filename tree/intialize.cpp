#include<bits/stdc++.h>
using namespace std;

struct Node {
   int data;
   Node *left;
   Node *right;
   Node(int val){
     data = val;
     left = right = NULL;
   }
};

void display(Node *root){
    if(root != NULL){
        display(root->left);
        cout << root->data << endl;
        display(root->right);
    }
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    display(root);

    return 0;
}