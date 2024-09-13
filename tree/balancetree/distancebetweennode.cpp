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
 *                  4      5   6     7
                 8     9          10
 */

void displayLeftView(Node *root){
     if(root == NULL) return;
     queue<Node *> q;
     q.push(root);
     while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node *temp = q.front();
            q.pop();
            if(i == 0){
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

Node *findLCA(Node *root, int n1, int n2){
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2){
        return root;
    } 

    Node *left = findLCA(root->left, n1, n2);
    Node *right = findLCA(root->right, n1, n2);
    
    if(left != NULL && right != NULL){
        return root;
    }
    
    if(left == NULL && right == NULL){
        return NULL;
    }

    if(left != NULL){
        return findLCA(left, n1, n2);
    }

    return findLCA(root->right, n1, n2);

}

int findDistanceFromLca(Node *lca, int n, int dist){
    if(lca == NULL) return -1;

    if(lca->data == n){
        return dist;
    }

    int left = findDistanceFromLca(lca->left, n , dist+1);
    if(left != -1){
        return left;
    }
    
    return findDistanceFromLca(lca->right, n , dist+1);

}


int findDistanceBetween(Node *root, int n1, int n2){
    Node *lca = findLCA(root, n1, n2);
    int d1 = findDistanceFromLca(lca, n1, 0);
    int d2 = findDistanceFromLca(lca, n2, 0);

    return d1+ d2;
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
    cout << findDistanceBetween(root, 2,10) << endl;

    return 0;
}