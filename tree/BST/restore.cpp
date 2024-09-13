#include<iostream>
#include<climits>
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

void inorderTraveal(Node *root){
    if(root != NULL){
      inorderTraveal(root->left);
      cout << root->data << " ";
      inorderTraveal(root->right);
    }
}


void swap(int *p , int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void calculatePointers(Node *root, Node **first, Node**last, Node**mid, Node **prev){
   
    if(root == NULL) return;
    
    calculatePointers(root->left, first, last, mid, prev);
    
    if(*prev && (*prev)->data > root->data){
       if(!*first){
           *first = *prev;
           *mid = root;
       }else{
           *last = root;
       }
    }
    *prev = root;
   
    calculatePointers(root->right, first, last, mid, prev);
    

}

void restoreTree(Node *root){
    if(root == NULL) return;
    Node *first = NULL, *last = NULL, *mid =NULL, *prev = NULL;

    calculatePointers(root, &first, &last, &mid, &prev);

    if(first != NULL && last != NULL){
        swap(&(first->data), &(last->data));
    }
    else if(first != NULL && mid != NULL){
        swap(&(first->data), &(mid->data));
    }
}


int main(){
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inorderTraveal(root);

    restoreTree(root);
    cout << "bst after restore" << endl;
    inorderTraveal(root);
    
    return 0;
}