#include<bits/stdc++.h>
using namespace std;

#define SIZE 10

struct item {
   int data;
   int key;
};

struct item * hashTable[SIZE];

struct item * init(int key, int data){
    struct item *temp = (struct item *) malloc(sizeof(struct item));
    temp->key = key;
    temp->data = data;
    return temp;
}

struct hashTable {
    int *arr; 
};
int hashCode(int key){
    return key % SIZE;
}

void insert(struct item *ite){
   int key = hashCode(ite->key);
   
   while(hashTable[key] != NULL){
      ++key;
      key = key % SIZE;
   }

   hashTable[key] = ite;
}

struct item * Search(int key2){
    int key = hashCode(key2);
    while(hashTable[key] != NULL){
        if(hashTable[key]->key == key){
            return hashTable[key];
        }

        ++key; 
        key = key % SIZE;
    }

    return init(0,0);
}

bool deleteItem(int key2){
    int key = hashCode(key2);
    while(hashTable[key] != NULL){
        if(hashTable[key]->key == key){
            hashTable[key] = NULL;
            return true;    
        }
        ++key; 
        key = key % SIZE;
    }

    return false;
}

int main(){
    struct item * item1, *item2;
    item1 = init(1, 34);
    insert(item1);
    item1 = init(2, 14);
    insert(item1);
  
    for(int i = 0; i < SIZE;i++){
        if(hashTable[i] != NULL){
           cout << "Data: " << hashTable[i]->data << endl;
        }
    }

    struct item *se;
    se = Search(4);
    cout << "Search Data: " << se->data << endl;

    deleteItem(1);

     cout << "After delete:  " <<endl;

     for(int i = 0; i < SIZE;i++){
        if(hashTable[i] != NULL){
           cout << "Data: " << hashTable[i]->data << endl;
        }
    }

    return 0;
}
