#include<bits/stdc++.h>
using namespace std;

struct node{
   int data;
   struct node *left, *right;
};

struct node *newNode(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *leftRotate(struct node *x){
      struct node *y = x->right;
      x->right = y->left;
      y->left = x; 
      return y;
}

struct node *rightRotate(struct node *x){
    struct node *y = x->left;
    x->left = y->right;
    y->right = y;
    return y;
}

struct node* splay(struct node * root, int data){
    if(root == NULL || root->data == data) return root;
    
    if(root->data > data){
        if(root->left == NULL) return root;
        if(root->left->data > data){
          root->left->left  = splay(root->left->left, data);
          root = rightRotate(root);
        } else{
          root->left->right = splay(root->left->right, data);
          if(root->left->right != NULL){
                root->left = leftRotate(root->left);
          }
        }
         return root->left == NULL ? root: rightRotate(root);
    } else{
        if(root->right == NULL) return root;
        if(root->right->data < data){
           root->right->right = splay(root->right->right, data);
           root = leftRotate(root);
        } else{
           root->right->left = splay(root->right->left, data);
           if(root->right->left != NULL){
              root->right = rightRotate(root->right);
           }
        }
        return (root->right == NULL) ? root: leftRotate(root);
    }

}

struct node *insert(struct node *root, int data){
    if(root == NULL) return newNode(data);
    root = splay(root, data);
    struct node *newdat = newNode(data);
    if(root->data > data){
        newdat->right = root;
        newdat->left = root->left;
        root->left = NULL; 
    } else{
        newdat->left = root;
        newdat->right = root->right;
        newdat->right = NULL;
    }
    return newdat;
}

struct node *search(struct node *root, int data){
    return splay(root, data);
}

struct node *deleteNode(struct node *root, int data){
    if(root == NULL) return root; 
    root = splay(root, data);
    struct node *temp;
    if(root->left == NULL){
        temp = root;
        root = root->right;
    } else if(root->right == NULL){
        temp = root;
        root = root->left;
    } else{
       temp = root;
       root = splay(root->left, data);
       root->right = temp->right;
    }

    free(temp);
    return root;
}

void printTree(struct node *root){
    if(root != NULL){
        printTree(root->left);
        cout << root->data << endl;
        printTree(root->right);
    }
}
void preOrder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		cout << root->data << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
}
int main(){
   node* root = newNode(34);
   root->left = newNode(15);
   root->right = newNode(40);
   root->left->left = newNode(12);
   root->left->left->right = newNode(14);
   root->right->right = newNode(59);
   cout << "The Splay tree is \n";
   printTree(root);
   int ele = 40;
   cout << "\nThe element to be searched: " << ele;
   root = search(root, ele);

   cout << "\nModified preorder traversal if element is found: ";
   preOrder(root);
}