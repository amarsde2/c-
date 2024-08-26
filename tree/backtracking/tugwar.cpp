#include<bits/stdc++.h>
using namespace std;



void algorithm(int *weight, int  n, bool curr[], int select, bool sol[], int &diff, int sum , int total, int pos){
    if(n == pos) 
       return;
    
    if((n/2-select) > (n - pos)) 
       return;
    
    algorithm(weight, n, curr, select, sol, diff, sum, total, pos+1);
    select++;
    curr[pos] = true;
    total += weight[pos];

    if(n/2 == select){
        if(abs(sum/2 - total) < diff){
            diff = abs(sum/2 - total);
            for(int i = 0; i <n;i++){
                sol[i] = curr[i];
            }
        }
    } else{
        algorithm(weight, n, curr, select, sol, diff, sum, total, pos+1);
    }

    curr[pos] = false;
}

void solveTugWarProblem(int *weight, int n){
    bool* sol = new bool[n];
    bool* cur = new bool[n];
   
    int diff = INT_MAX;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sol[i] = false;
        cur[i] = false;
        sum += weight[i];
    }

    algorithm(weight, n, cur, 0, sol , diff, sum, 0 ,0);
 
    cout << "left " << endl;
    for(int i = 0; i < n; i++){
        if(sol[i] == true){
            cout << weight[i] << " " ;
        }
    }
    cout << endl;
    cout << "Rights: " << endl;
    for(int i = 0; i < n; i++){
        if(sol[i] == false){
            cout << weight[i] << " " ;
        }
    }
}

int main(){
    int weights[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = 11;
    solveTugWarProblem(weights, n);
}