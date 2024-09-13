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
       static int idx = end;
       int curr = preorder[idx];
       idx--;
       Node * node = new Node(curr);
       if(start == end){
         return node;
       }
       
       int pos =  searchPosition(inorder, start, end, curr);
      
       node->right = BuildTree(preorder, inorder, pos+1, end);
       node->left = BuildTree(preorder, inorder, start,  pos-1);
     

       return node;
}

void display(Node *root){
    if(root != NULL){
        
        cout << "Node " << root->data << endl;
        display(root->left);
        display(root->right);
    }
}

int sumOfKLevel(Node *root, int level){
    if(root == NULL) return -1;
    queue<Node *> q;
    int cl = 0;
    q.push(root);
    q.push(NULL);
    int sum = 0;

    while(!q.empty()){
        Node *n = q.front();
        q.pop();
        if(n != NULL){
            if(cl == level){
                sum += n->data;
            }
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        } else if( n == NULL){
            if(!q.empty()){
                q.push(NULL);
                cl++;
            }
        }
    }

    return sum;
}

void levelOrderTravel(Node *root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *visit = q.front();
        q.pop();
        if(visit != NULL){
            cout << visit->data << endl;
            if(visit->left){
              q.push(visit->left);
            }
            if(visit->right){
                q.push(visit->right);
            }  
        } else if(visit == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }   
    }
}

int allNodesIntree(Node *root){
    int total = 0;
    if(root == NULL) return 0;
    total  += 1;
    total += allNodesIntree(root->left);
    total += allNodesIntree(root->right);

    return total;
}

int allSumNodesIntree(Node *root){
    if(root == NULL) return 0;

    return allSumNodesIntree(root->left) + allSumNodesIntree(root->right) + root->data;
}

int calculateHight(Node * root){
    if(root == NULL) return 0;
    return max(calculateHight(root->left), calculateHight(root->right)) + 1;
}

int calculateDiect(Node *root , int *height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int left = 0; 
    int right = 0;
    
    int leftDict = calculateDiect(root->left, &left);
    int rightDict = calculateDiect(root->right, &right);
    int currentDict = left + right + 1;
    *height = max(left, right) + 1;

    return max(currentDict,  max(leftDict, rightDict));

}

void SumReplacement(Node *root){
    if(root == NULL){ 
        return ;
    }

    SumReplacement(root->left);
    SumReplacement(root->right);
    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->right != NULL){
       root->data += root->right->data;
    }
    
}

int main(){
    int post[] = {4, 2, 5, 3, 1};
    int inr[] = {4, 2, 1, 5, 3};
    Node *root = BuildTree(post, inr, 0, 4);
    //display(root);
    //levelOrderTravel(root);
    //cout << sumOfKLevel(root, 2) << endl;
    //cout << allNodesIntree(root) << endl;
    //cout << allSumNodesIntree(root) << endl;
    // cout << calculateHights(root) << endl;
    int height = 0;
    SumReplacement(root);
    cout << "Displaying" << endl;
    display(root);
    return 0;
}