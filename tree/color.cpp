#include<bits/stdc++.h>
using namespace std;

#define V 4

bool graph[V][V] = {
   {0, 1, 1, 0},
   {1, 0, 1, 1},
   {1, 1, 0, 1},
   {0, 1, 1, 0},
};


bool is_valid(int v , int color[], int c){

    for(int i = 0; i < V; i++){
      if(graph[v][i] && c == color[i]){
        return false;
      }
    }
    return true;
}

bool mColor(int cols, int color[], int vertix){
    if(V == vertix) return true;
    for(int i = 1; i <= cols; i++){
        if(is_valid(vertix, color, i)){
            color[vertix] = i;
            if(mColor(cols,color, vertix+1) == true){
                return true;
            } 
            color[vertix] = 0;           
        }
    }

    return false;

}

int main(){
    int colors = 3;
    int color[V];
    for(int i = 0; i < V; i++){
        color[i] = 0;
    }

    if(mColor(colors, color, 0) == false){
        cout << "Solution does not exist!" << endl;
    }

    for(int i = 0; i < V; i++){
        cout << color[i] << endl;
    }
    
} 