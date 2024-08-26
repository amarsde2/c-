#include<bits/stdc++.h>
using namespace std;
#define MAX 9999
int n = 4;

int design[20][20] = {
   {0, 22, 26, 30},
   {30, 0, 45, 35},
   {25, 45, 0, 60},
   {30, 35, 40, 0}
};

int DP[32][8];
int visited = (1 << n) -1;

int tsp(int mark, int position){
    
    if(mark == visited){
        return design[position][0];
    }

    if(DP[mark][position] != -1){
        return DP[mark][position];
    }

    int answer = MAX;

    for(int city = 0 ;  city < n ; city++){
        if((mark & (1 << city)) == 0){
            int newanswer = design[position][city] + tsp(mark|(1 << city), city);
            answer = min(answer, newanswer);
        }
    }

    return DP[mark][position] = answer;
}

int main(){
    for(int i = 0 ; i < (1 << n); i++){
        for(int j = 0; j < n ; j++){
            DP[i][j] = -1;
        }
    }

    cout << tsp(1,0)<< endl;

    return 0;
}