#include<bits/stdc++.h>
using namespace std;
#define MAX_ELEMENTS 10
#define MAX_SETS 5


int setCover(int x[], int Subset[MAX_SETS][MAX_ELEMENTS],int output[], int nset, int nelem){
    int U[nelem];
    for(int i=0;i<nelem;i++){
        U[i] = x[i];
    }
    int selectedSet[nset];
    for(int i = 0;i<nset;i++){
        selectedSet[i] = false;
    }
  
    int outputIndexId = 0;

    while(outputIndexId < nset){
        int maxIntersection = 0;
        int selectedIndex = -1;
        for(int i = 0; i < nset; i++){
            if(selectedSet[i] == false){
                int intersection = 0;  
                for(int j = 0 ; j < nelem; j++){
                    if(U[j] && Subset[i][j]){
                      intersection++;
                    }
                }

                if(intersection > maxIntersection){
                  maxIntersection = intersection;
                  selectedIndex = i;
                }

              
            }
        }

          if(selectedIndex == -1){
                   break;
                }

                selectedSet[selectedIndex] = true;
         
                for(int j = 0; j < nelem; j++){
                
                    U[j] = U[j] - Subset[selectedIndex][j];
                }
          
                output[outputIndexId++] = selectedIndex;

    }  
    
    return outputIndexId;
}

int main(){
    int X[MAX_ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int S[MAX_SETS][MAX_ELEMENTS] = {
      {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}
    };
    int numSets = 5;
    int numElements = 10;
    int output[numSets];
    int numofselectedSets = setCover(X, S, output, numSets, numElements);

    for(int i = 0; i < numofselectedSets; i++){
        cout << output[i] << endl;
    }

    return 0;
}