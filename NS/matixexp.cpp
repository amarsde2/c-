#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multiple(vector<vector<int>> &a, vector<vector<int>> &b){
    int sz = a.size();
    vector<vector<int>> ans(sz, vector<int>(sz,0));
    for(int i = 0; i < sz; i++){
      for(int j = 0; j < sz; j++){
         for(int k = 0; k < sz; k++){
            ans[i][j] += a[i][k] * b[k][j];
          }
      }
    }
    return ans;
}

vector<vector<int>> matrixExponent(vector<vector<int>> &a, int n){
    if(n == 0){
        int sz = a.size();
        vector<vector<int>> ans(sz, vector<int>(sz,0));
        for(int i = 0; i < sz; i++){
          for(int j = 0; j < sz; j++){
              ans[i][j] = 1;
          }
        }
        return ans;
    }

    if(n == 1){
        return a;
    }


    vector<vector<int>> temp = matrixExponent(a, n/2);

    vector<vector<int>> ans = multiple(temp, temp);

    if(n & 1){
         ans = multiple(ans, a);
    }

    return ans;

}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> a = {{1, 1},{1,0}};
    
    vector<vector<int>> ans = matrixExponent(a, n);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++)
        {
            cout << ans[i][j] << endl;
        }
    }

    return 0;
}