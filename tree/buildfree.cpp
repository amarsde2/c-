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

int searchPosition(int inorder[], int start, int end, int curr){
    for(int i = start; i <= end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

Node * BuildTree(int preorder[], int inorder[], int start, int end){
       if(start > end){
          return NULL;
       }
       static int idx = 0;
       int curr = preorder[idx];
       idx++;
       Node * node = new Node(curr);
       int pos =  searchPosition(inorder, start, end, curr);
       if(start == end){
         return node;
       }
       node->left = BuildTree(preorder, inorder, start,  pos-1);
       node->right = BuildTree(preorder, inorder, pos+1, end);

       return node;
}

void display(Node *root){
    if(root != NULL){
        display(root->left);
        cout << "Node " << root->data << endl;
        display(root->right);
    }
}

int main(){
    int pre[] = {1, 2, 4, 3, 5};
    int inr[] = {4, 2, 1, 5, 3};
    Node *root = BuildTree(pre, inr, 0, 4);
    display(root);

    return 0;
}