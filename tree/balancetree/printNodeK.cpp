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

void printNodePresentAtDist(Node *root , int k){
    if(root == NULL || k < 0) return;

    if(k == 0){
        cout << root->data << endl;
        return;
    }

    printNodePresentAtDist(root->left, k-1);
    printNodePresentAtDist(root->right, k-1);
}

int findNodeKDistance(Node *root, Node *target, int distance){
    if(root == NULL) return -1;

    if(root == target){
        printNodePresentAtDist(root , distance);
        return 0;
    }
    
    int dl = findNodeKDistance(root->left, target, distance);

    if(dl != -1){
         if(dl + 1 == distance){
            cout << root->data << endl;
         } else{
            printNodePresentAtDist(root->right, distance - dl - 2);
         }

         return 1 + dl;
    }

    int dr = findNodeKDistance(root->right, target, distance);

    if(dr != -1){
         if(dr + 1 == distance){
            cout << root->data << endl;
         } else{
            printNodePresentAtDist(root->left, distance - dr - 2);
         }

         return 1 + dr;
    }

    return -1;
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
    findNodeKDistance(root, root->left->right,2); 

    return 0;
}