#include<iostream>
using namespace std; 

int * newArr(int olds[]) {
    static int sas[] = {1,2,3,4,5,6};
    
    for(int i = 0; i < size(sas); i++){
        sas[i] = olds[i] * sas[i];
    }

    return sas;
}

int main(){
    
    int myArr[] = {1,2,3,4,5,6};
    int *p;
    
    p = newArr(myArr);
    
    for(int i=0; i < size(myArr); i++){
        cout << *(p+i) << endl;
    }

    return 0;
}