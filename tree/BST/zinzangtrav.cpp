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


void zinZagTraversal(Node *root){
    if(root == NULL) return;
    stack<Node *> currentStack;
    stack<Node *> nextStack;
    bool leftToRight = true;
    currentStack.push(root);

    while(!currentStack.empty()){
        Node *temp = currentStack.top();
        currentStack.pop();
        if(temp){
            cout << temp->data << endl;
            if(leftToRight){
                if(temp->left){
                   nextStack.push(temp->left);
                }
                if(temp->right){
                  nextStack.push(temp->right);
                }
            } else{
            
                if(temp->right){
                  nextStack.push(temp->right);
                }

                if(temp->left){
                   nextStack.push(temp->left);
                }
            }
        }

        if(currentStack.empty()){
            swap(currentStack, nextStack);
            leftToRight = !leftToRight;
        }
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
    BST_INSERT(root, 2);
    BST_INSERT(root, 5);
    BST_INSERT(root, 3);
    BST_INSERT(root, 9);
    BST_INSERT(root, 8);
    BST_INSERT(root, 7);    
    zinZagTraversal(root);
   
    return 0;
}