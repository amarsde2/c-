#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

#define rca(i,a,b) for(int i = a; i < b; i++);
#define vi vector<int>


void heapify(vi &a, int n, int large){
    int i = large;
    int left = 2 * large +1;
    int right = 2 * large + 2;

    if(left < n && a[left] > a[i]){
        i = left;
    }

    if(right < n && a[right] > a[i]){
        i = right;
    }

    if(i != large){
        swap(a[i], a[large]);
        heapify(a, n, i);
    }
}

void heapsort(vi &a, int n){
    for(int i= n/2-1; i >= 0; i--){
       heapify(a, n, i);
    }

    for(int i = n-1; i > 0; i--){
      swap(a[0], a[i]);
      heapify(a, i, 0);
    }
}

int main(){
    int n ; 

    cin >> n;
    vi a(n);
    for(auto & i : a){
      cin >> i;
    }
    
    heapsort(a, n);

    for(auto  &i : a){
      cout << i << " ";
    }

    cout << endl;

    return 0;
}