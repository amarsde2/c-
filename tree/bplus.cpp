#include<bits/stdc++.h>
using namespace std;

struct Bnode{
    int *keys;
    Bnode **childs;
    int n;
    bool leaf;
};

Bnode * root = NULL;
Bnode * x = NULL;
Bnode * y = NULL;
Bnode * np = NULL;

int t = 5;

void display(Bnode *node){
    int i;
    for(i = 0 ; i < node->n; i++){
        if(node->leaf == false){
            display(node->childs[i]);
        }

        cout << node->keys[i] << endl;
    }

    if(node->leaf == false){
        display(node->childs[i]);
    }

}


Bnode * init(){
    int i; 
    
    np = new Bnode;
    np->keys = new int[t-1];
    np->childs = new Bnode *[t];
    np->leaf = true;
    np->n = 0;
    
    for(i = 0; i < t; i++){
        np->childs[i] = NULL;
    }

    return np;

}
int split(int index, Bnode *node){

    struct Bnode *np3, *np1;
    int j, mid;
    np3 = init();
    int half = t / 2;
    if(index == -1){
        mid = node->keys[half-1];
        node->keys[half-1] = 0;
        node->n--;
        np1 = init();
        np3->leaf = true;
        node->leaf = true;
        np1->leaf = false;

        for(j = half+1; j < node->n; j++){
            np3->keys[j-(half+1)] = node->keys[j];
            np3->n++;
            node->keys[j] = 0;
            node->n--;
        }

        for(j = 0; j < node->n; j++){
            node->childs[j] = NULL;
        }

        np1->keys[0] = mid;
        np1->childs[np1->n] =node;
        np1->childs[(np1->n) +1] = np3;
    }else{
        y = node->childs[index];
        mid = y->keys[half-1];
        y->keys[half-1] = 0;
        y->n--;

        for(j = half+1; j < y->n; j++){
            np3->keys[j-(half+1)] = y->keys[j];
            np3->n++;
            y->keys[j] = 0;
            y->n--;
        }

        node->childs[index] = y;
        node->childs[index+1] = np3;
    }

    return mid;
}

void sort(int *p , int n){
    int tmp,i,j;
    for(i = 0; i < n; i++){
        for(j = i; j <= n; j++){
            if(p[i] > p[j]){
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    } 
}

void insert(int key){
    int i,v;
    if(x == NULL){
       root = init();
       x  = root;
    } else{
        if(x->leaf == true && x->n == t-1){
          v = split(-1, x);
          x = root;
    
          for(i = 0; i < x->n; i++){
            if(key > x->keys[i] && key < x->keys[i+1]){
                i++;
                break;
            } else if(key < x->keys[0]){
                break;
            } else{
                continue;
            }
          }

          x = x->childs[i];
        } else{
          while(x->leaf == false){
            for(i = 0; i < x->n; i++){
                if(key > x->keys[i] && key < x->keys[i+1]){
                    i++;
                    break;
                } else if(key < x->keys[0]){
                    break;
                } else{
                    continue;
                }
            }    
          
            if(x->childs[i]->n == t-1){
                v = split(i, x);
                x->keys[x->n] = v;
                x->n++;
                continue;
            } else{
               
                x  = x->childs[i];
            }
          }
        }
    }

    x->keys[x->n] = key;
    sort(x->keys, x->n);
    x->n = x->n+1;
}






int main(){
    
    insert(19);
    insert(20);
    insert(13);
    insert(32);
    display(root);

    return 0;
}