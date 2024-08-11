#include<bits/stdc++.h>
using namespace std;

struct node {
   int data;
   struct node *left, *right;
};

struct node *root = NULL;
struct node *current = NULL;
void insert(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
     
    if(root == NULL){
        root = temp;
    } else{
        struct node *parent = NULL;
        current = root;
        while(1){
            parent = current;
            if(data < parent->data){
                current = current->left;
                if(current == NULL){
                    parent->left = temp;
                    return;
                }
            } else{
                current = current->right;
                if(current == NULL){
                    parent->right = temp;
                    return;
                }
            }
        }
    }
}

struct node * search(int data){
    current = root;
    if(data != current->data){
        if(data < current->data){
            current = current->left;
        } else{
            current = current->right;
        }
    }   
    return current;
}

void printTree(struct node *root){
    if(root != NULL){
        printTree(root->left);
        cout << root->data << endl;
        printTree(root->right);
    }
}


int main(){
   struct node *searc;
   insert(55);
   insert(20);
   insert(90);
   insert(50);
   insert(35);
   insert(15);
   insert(65);
   cout<<"Insertion done\n";
   cout<<"BST:"<<endl;
   printTree(root);

   searc = search(90);

   if(searc != NULL){
      cout <<  "data found" << searc->data << endl;
   } else{
      cout << "Data not found " << endl;
   }


   return 0;
}