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

void displayRightView(Node *root){
     if(root == NULL) return;
     queue<Node *> q;
     q.push(root);
     while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node *temp = q.front();
            q.pop();
            if(i == n - 1){
               cout << temp->data << endl;
            }    

            if(temp->left){
               q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
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
    displayRightView(root);

    return 0;
}