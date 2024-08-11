#include<bits/stdc++.h>
using namespace std;


/* function to sort elements in array using selection sort algorithm */
void selectionSort(int arr[], int n){
    
    int tmp;
    for(int i = 0; i < n -1; i++){
        for(int j = i+ 1; j < n; j++){
            if(arr[i] > arr[j]){
               tmp = arr[i];
               arr[i] = arr[j];
               arr[j] = tmp;
            }
        }
    }
}


/* function to sort elements in array using bubble sort algorithm */
void bubbleSort(int arr[], int n){
    int counter = 0;
    int tmp;
    while(counter < n){
        for(int i = 0 ; i < n - counter - 1; i++){
            if(arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
        counter++;
    }
}

/* function to sort elements in array using bubble sort algorithm */
void insertSort(int arr[], int n){
     
    for(int i = 1; i < n ; i++){
        int current = arr[i];
        int j = i - 1;

        while(arr[j] > current && j >= 0){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }
}



int main(){
    
    int n;
    int arr[n];

    cin >> n; 

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 

    //selectionSort(arr,n);
    // bubbleSort(arr, n);
    
    insertSort(arr, n);

    cout << endl;
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    } 

    return 0;

}