#include<bits/stdc++.h>
using namespace std;
#define inf 99999

int minDist(int vistied[], int dist[]){
    int min_val = inf, id;
    for(int k=0; k < 6; k++){
        if(vistied[k] == 0 && dist[k]<= min_val){
            min_val = dist[k];
            id = k;
        }
    }
    return id;
}


void greedy_dijsktra(int grap[6][6], int source){
    int vistied[6];
    int dist[6];
    for(int i=0; i<6; i++){
        vistied[i] = 0;
        dist[i] = inf;
    }
    
    dist[source] = 0;

    for(int k = 0; k < 6; k++){
       int m = minDist(vistied, dist);
       vistied[m] = 1;
       
       for(int j = 0; j < 6; j++){
          if(vistied[j] == 0 && grap[m][j] && dist[m] != inf && dist[m] + grap[m][j] < dist[j]){
            dist[j] = dist[m] + grap[m][j];
          }
       }
    }
  
    for(int k = 0; k < 6; k++){
        cout << dist[k] << " " << endl;
    }
}


int main(){
int graph[6][6]= {
      {0, 1, 2, 0, 0, 0},
      {1, 0, 0, 5, 1, 0},
      {2, 0, 0, 2, 3, 0},
      {0, 5, 2, 0, 2, 2},
      {0, 1, 3, 2, 0, 1},
      {0, 0, 0, 2, 1, 0}
   };
   greedy_dijsktra(graph,0);
   return 0;
}