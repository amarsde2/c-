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



void inorderTraveal(Node *root){
    if(root != NULL){
      inorderTraveal(root->left);
      cout << root->data << " ";
      inorderTraveal(root->right);
    }
}

Node *SEARCH_BST(Node *root , int key){
    if(root == NULL) return NULL;
    
    if(root->data == key){
        return root;
    }

    if(root->data < key){
        return SEARCH_BST(root->right, key);
    }

    return SEARCH_BST(root->left, key);
}

Node *inorder_sucessor(Node *root){
      
    Node *curr  = root;
    while(curr != NULL && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node * DELETE_IN_BST(Node *root, int key){
    if(root == NULL){
        cout << "key not found";
    } else if(root->data > key){
        root->left = DELETE_IN_BST(root->left, key);
    } else if(root->data < key){
        root->right = DELETE_IN_BST(root->right, key);
    } else{
        Node *temp;
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        } else{
            temp = inorder_sucessor(root->right);
            root->data = temp->data;
            root->right = DELETE_IN_BST(root->right, temp->data);
        }
    }

    return root;
}


int main(){
    Node *root = new Node(1);
    BST_INSERT(root, 2);
    BST_INSERT(root, 5);
    BST_INSERT(root, 3);
    BST_INSERT(root, 9);
    BST_INSERT(root, 8);
    BST_INSERT(root, 7);    
    inorderTraveal(root);
    cout << endl;
    cout << "Seaching in bst" << endl;
    Node *temp = SEARCH_BST(root, 9);
    if(temp){
        cout << temp->data << endl;
    } else{
        cout << "Data not found" << endl;
    }


    DELETE_IN_BST(root, 8);
    cout << "bst after node deletion" << endl;
    inorderTraveal(root);
    
    return 0;
}