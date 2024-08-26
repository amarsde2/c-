#include<bits/stdc++.h>
using namespace std;
using namespace std;
struct Job {
   char id;
   int deadLine;
   int profit;
};

bool compare(Job j1, Job j2){
    return j1.profit > j2.profit;
}

int min(int a, int b){
    return a < b ? a : b;
}
int n = 5;

int main(){
    Job jobs[] = { 
                  { 'a', 3 , 100 },
                  { 'b', 2, 20 },
                  { 'c', 1, 40 },
                  { 'd', 4, 80 },
                  { 'e', 2, 60 }
        };
    
    sort(jobs, jobs+n, compare);
    
    int slots[n] ;
    int jobSq[n];
    for(int i=0; i<n; i++){
       slots[i] = false;
    }
    int profit = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = min(n, jobs[i].deadLine)-1; j >= 0; j--){
            if(slots[j] == false){
                slots[j] = true;
                jobSq[j] = i; 
                profit += jobs[i].profit;
                break;
            }
        }       
    }

    for(int i = 0; i < n ; i++){
        if(slots[i] == true){
            cout << jobs[jobSq[i]].id << endl;
        }
    }

    cout << profit << endl;
}