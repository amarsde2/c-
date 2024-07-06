#include<iostream>
using namespace std; 

int main(){
 
    /* 
     * Author  Amar kumar   
     * description:- Program to insert one or more elements into the array  
     */

    int n; // size of array; 
    int array[n] = {};

    cout << "Progam start... " << endl;
    cout << "Enter a number of elements to insert into the array: "; 
    cin >> n;

    for(int  i= 0; i < n; i++){
        cout << "Enter element "; 
        cin >> array[i]; 
        cout << endl;
    }

    cout << "Printing your array information ..." <<  endl;

    for(int  i= 0; i < n; i++){
        cout <<  array[i] << endl;
    }


    cout << "Program End ..." << endl;

    return 0;
}