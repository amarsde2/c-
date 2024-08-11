#include<bits/stdc++.h>
using namespace std;

struct heap{
   int *data;
   int size;
   int capacity;
};

heap * createHeap(int capacity){
    heap *myheap = new heap;
    myheap->capacity = capacity;
    myheap->data = new int[capacity];
    myheap->size = 0;
    return myheap;
}

void swap(int& a, int& b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}


void heapfy(heap *myhead, int index){
    int large = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < myhead->size && myhead->data[left] >  myhead->data[large]){
       
        large = left;
    }

    if(right < myhead->size && myhead->data[right] >  myhead->data[large]){
       
        large = right;
    }
    

    if(index != large){
       swap(myhead->data[index], myhead->data[large]);
       heapfy(myhead, large);
    }

}

int deleteHeap(heap *myheap, int key){
    if(myheap->size == 0){
        cout << "Heap is empty !" << endl;
    }

    int temp = myheap->data[0];

    myheap->data[0] = myheap->data[myheap->size -1];

    heapfy(myheap,0);

    return temp;
}



void insert(heap *myheap, int data){
    if(myheap->capacity == myheap->size){
        cout << "Heap capacity is overflow! " << endl;
        return;
    }
    int i  = myheap->size++;
    myheap->data[i] = data;
    
   
    while(i!= 0 && myheap->data[(i-1)/2] < myheap->data[i]){
        swap(myheap->data[(i-1)/2],myheap->data[i]);
        i = (i - 1)/2; 
    }

    return;
}

void displayHeap(heap *myheap){
    if(myheap->size == 0){
        cout << "Heap is empt! " << endl;
        return;
    }

    for(int i = 0 ; i < myheap->size; i++ ){
        cout << myheap->data[i] << endl;
    }
    
    return;
}


int main(){
    heap *myheap = createHeap(10);
    insert(myheap, 11);
    insert(myheap, 12);
    insert(myheap, 10);
    insert(myheap, 13);
    insert(myheap, 14);
    
    displayHeap(myheap);
    cout << "Heap after delete" << endl;
    int data = deleteHeap(myheap,10);
    cout << data << endl;
    return 0;
}


