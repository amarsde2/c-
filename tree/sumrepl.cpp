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


void SumReplacement(Node *root){
    if(root == NULL){ 
        return ;
    }

    SumReplacement(root->left);
    SumReplacement(root->right);
    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
       root->data += root->right->data;
    }
    
}
void display(Node *root){
    if(root != NULL){
        
        cout << "Node " << root->data << endl;
        display(root->left);
        display(root->right);
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
    SumReplacement(root);
    cout << "Displaying" << endl;
    display(root);
    return 0;
}