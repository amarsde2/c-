#include<bits/stdc++.h>
using namespace std;


void display(int set[], int size){
    for(int i = 0; i < size;i++){
       cout << set[i] << " "; 
    }
    cout << endl;
}

void findallcomination(int set[], int subset[], int size, int subsetIndex, int total, int nodecout, int sum){
     
    if(total == sum){
        display(subset, subsetIndex);
        findallcomination(set, subset, size, subsetIndex-1, total - set[nodecout], nodecout+1, sum);
    } else{
        for(int i = nodecout; i < size; i++){
           subset[subsetIndex] = set[i];
           findallcomination(set, subset, size, subsetIndex+1,total + set[i],i+1, sum);
        }
    }
}


void findsubset(int set[], int size, int sum){
    int *subset = new int[size];
    findallcomination(set, subset, size, 0, 0, 0, sum);
    delete[] subset;
}

int main(){
    int set[] = {1, 9, 7, 5, 18, 12, 20, 15};
    int size  = 7;

    findsubset(set, size, 35);

    return 0;
}