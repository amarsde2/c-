#include<iostream>
using namespace std; 

int main(){

    /* 
     * Author  Amar kumar   
     * description:- Program to delete element based on the value of element into the given array  
     */
    int n = 5;
    int array[n] = {1,2,3,4,5};
    int k;

    cout << "Progam start... " << endl;
    cout << "Enter a number which you want to delete from the array [1,2,3,4,5] "; 
    cin >> k;

    for(int  i= 0; i < n; i++){
        if(array[i] == k){
            for(int j = i; j < n; j++){
                array[j] = array[j+1];
            }
            n--;
        }
    }


    cout << "Printing your array information ..." <<  endl;

    for(int  i= 0; i < n; i++){
        cout <<  array[i] << endl;
    }

    cout << "Program End ..." << endl;

    return 0;
}