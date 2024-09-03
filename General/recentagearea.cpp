#include<bits/stdc++.h>
using namespace std;
#define INF 9999
int main(){
    /*
    int arr[] = {2,1,5,6,2,3};
    int n = 6;
    int ans = 0;
    
    // approach first
    for (int i = 0; i < n; i++){
        int minh = INF;
        for(int j = i; j < n; j++){
            minh = min(arr[j], minh);
            int len = j - i + 1;
            ans = max(ans, len * minh);
        }
    }

    */

    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int n = arr.size();
    stack<int> st;
    int ans = 0;
    int i = 0;
    arr.push_back(0);  // Sentinel value to ensure stack is emptied

    while (i < arr.size()) {  // Loop should run till arr.size() to include the sentinel 0
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int t = st.top();
            int h = arr[t];
            st.pop();
            if (st.empty()) {
                ans = max(ans, h * i);  // Width is entire current span if stack is empty
            } else {
                int len = i - st.top() - 1;  // Width is between current and previous higher bar
                ans = max(ans, len * h);
            }
        }
        st.push(i);
        i++;
    }

    cout << ans << endl;  // Output the maximum rectangle area
    return 0;
}