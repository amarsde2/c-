#include<bits/stdc++.h>
using namespace std;
#define V 5
int graph[V][V] = {
    {1,0,1,0,1},
    {1,1,1,1,1},
    {0,1,0,1,0},
    {1,0,0,1,1},
    {1,1,1,0,1}
};

int sol[V][V];

bool isValid(int x, int y){
   
    if(x >= 0 && x < V && y >=0 && y < V && graph[x][y] == 1){
        return true;
    }
    return false;
}


bool ratMazeProblem(int start, int end, int sol[V][V]){
     
    if(start == V-1 && end == V-1){
        sol[start][end] =1;
        return true;
    }
    
  
    if(isValid(start, end)){
        sol[start][end] =1;
        if(ratMazeProblem(start+1, end, sol) == true){
           return true ;
        }
        if(ratMazeProblem(start, end+1, sol) == true){
           return true ;
        }
        sol[start][end] = 0;
    }
       
    return false;
}


int main(){

    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
          sol[i][j] = 0;
        }
    }

    if(ratMazeProblem(0, 0,sol)){
        cout << "solution exists" << endl;
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
               cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        
    } else{
        cout << "solution does not exist" << endl;
    }



    return 0;
}
