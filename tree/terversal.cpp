#include<bits/stdc++.h>
using namespace std;

struct Tree{
   int data;
   struct Tree *left, *right;
};

struct Tree *root = NULL;
struct Tree *current = NULL;

void insert(int data){
    struct Tree *node = (struct Tree *) malloc(sizeof(struct Tree));
    node->data  = data;
    node->left = NULL;
    node->right = NULL;
    struct Tree *parent;
    
    if(root == NULL){
        root = node;
    } else{
        parent = NULL;
        current = root;
        while(1){
           parent = current;
           if(data < parent->data){     
                current = current->left;
                if(current == NULL){
                    parent->left = node;
                    return ;
                }
           } else{
                current = current->right;
                if(current == NULL){
                    parent->right = node;
                    return;
                }
           }
        }
    }

}

void inorder(struct Tree *root){
      if(root != NULL){
     inorder(root->left);
     cout << root->data <<  endl;
     inorder(root->right);
      }
}

void preorder(struct Tree *root){
    if(root != NULL){
        cout << root->data <<  endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Tree *root){
     if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data <<  endl;
     }
}


int main(){
      int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

    for(int i = 0; i < 7; i++){
        insert(array[i]);
    }

 preorder(root);
    cout << "In order "<< endl;
    inorder(root);
   
    cout << "Post order" << endl;

    postorder(root);

    return 0;
}