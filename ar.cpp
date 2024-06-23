#include<iostream>
using namespace std;

int main(){
    /* write a program to copy elements from one arr to another array in reverse order */
   
    int arr[] = {1,2,3,4,5,6,7,8};
 
    /*
    int copy[size(arr)];
    int j = 0;
    for(int i = 0; i < size(arr); i++){
        j = size(arr) - 1 - i;
        copy[i] = arr[j]; 
    }
    
    for(int i = 0; i < size(arr); i++){
        cout << copy[i] << endl;
    }
    
    */

    /* write a program to reverse array elements without using extra array*/
   
    int start = 0,tmp; 
    int end  = size(arr)- 1;
    
    while(start < end) {
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;  
        start++;
        end--;
    }

    for(int i = 0; i < size(arr); i++){
        cout << arr[i] << endl;
    }

    return 0;
}