#include<bits/stdc++.h>
using namespace std;

int arr[] = {11,20,10,18,29,39,30,20,49};

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int makePartion(int low, int high, int pivot){
    int lower = low-1;
    int higher = high;

    while(true){
        while(arr[++lower] < pivot){

        }

        while(higher > 0 && arr[--higher] > pivot){

        }

        if(lower >= higher){
            break;
        } else{
            swap(arr[lower], arr[higher]);
        }
    }

    swap(arr[lower], arr[high]);

    return lower;
}

void quickSort(int low, int high){
   
    if(high -low <= 0){
        return;
    } else{
        int pivot = arr[high];
        int middle = makePartion(low,  high, pivot);
        quickSort(low, middle-1);
        quickSort(middle+1, high);
    }

}
int main(){
 
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    quickSort(0,n-1);
    cout << endl;
    for(i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}