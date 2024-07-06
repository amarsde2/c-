#include<iostream>
using namespace std; 

int main(){
 
    /* 
     * Author  Amar kumar   
     * description:- Program to delete kth element into the given array  
     */
    int n = 5;
    int array[n] = {1,2,3,4,5};
    int k;

    cout << "Progam start... " << endl;
    cout << "Enter a kth position into the array which you want to delete "; 
    cin >> k;

    for(int i = k-1; i < n; i++){
        array[i] = array[i+1]; 
    }

    n--;

    cout << "Printing your array information ..." <<  endl;

    for(int  i= 0; i < n; i++){
        cout <<  array[i] << endl;
    }

    cout << "Program End ..." << endl;

    return 0;
}