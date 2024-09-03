#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> ar = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = ar.size();
    stack<int> st;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(!st.empty() && ar[st.top()]  < ar[i]){
            int cur = st.top();
            st.pop();
            if(st.empty()){
                break;
            } else{
                int diff = i - st.top() - 1;
                ans += (min(ar[st.top()],ar[i]) - ar[cur]) * diff;
            }

        }

        st.push(i);
    }

    cout << ans << endl;
}