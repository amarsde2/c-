#include<bits/stdc++.h> 
using namespace std;
#define pi pair<int,int>

int main(){
    int  k;
    cin >> k;
    vector<vector<int>> a(k);

    // Reading k sorted arrays
    for(int i = 0; i < k; i++){
        int size;
        cin >> size;
        a[i] = vector<int>(size);

        for(int j = 0; j < size; j++){
           cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0); // To track the current index in each array
    priority_queue<pi, vector<pi>, greater<pi>> pq; // Min-heap to store pairs {value, array index}
   
    // Initialize the priority queue with the first element of each array
    for(int i = 0; i < k; i++){
        if (a[i].size() > 0) {
            pq.push({a[i][0], i}); // Push {element, array_index} into the heap
        }
    }

    vector<int> ans;

    // Extract the smallest element and push the next element from the same array into the heap
    while(!pq.empty()){
       pair<int, int> x = pq.top(); // {value, array_index}
       pq.pop();

       ans.push_back(x.first); // Store the smallest element in the result

       // Get the array index and increase the index for that array
       if(idx[x.second] + 1 < a[x.second].size()){  // Check if there are more elements in the same array
          idx[x.second]++; // Move to the next element in this array
          pq.push({a[x.second][idx[x.second]], x.second}); // Push the next element of the array into the heap
       }
    }

    // Output the result
    cout << "answer: " << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
