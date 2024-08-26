#include<bits/stdc++.h>
using namespace std;

int mergeOptimal(int files[], int n){
    
    int ocost = 0;
    for(int i=0; i< n-1; i++){
        bool swal = false;
        for(int j = 0 ; j < n - i -1; j++){
            if(files[j] > files[j+1]){
                swap(files[j], files[j+1]);
                swal = true;
            }
        }
        if(swal == false){
            break;
        }
    }
    
    while(n > 1){

        int mergedSize = files[0] + files[1];
        ocost += mergedSize;
        files[0] = mergedSize;
       
        for(int i = 1; i < n-1; i++){
            files[i] = files[i+1];
        }
        n--;

        for(int i=0; i< n; i++){
            bool swal = false;
            for(int j = 0 ; j < n - i -1; j++){
                if(files[j] > files[j+1]){
                    swap(files[j], files[j+1]);
                    swal = true;
                }
            }

            if(swal == false){
                break;
            }
        }
    }


    return ocost;

}




int main(){
    int files[] = {5, 10, 20, 30, 30};
    int cost; 
    int n  = sizeof(files)/sizeof(files[0]);
    cost = mergeOptimal(files, n);

    cout << cost << endl;

    return 0;
}