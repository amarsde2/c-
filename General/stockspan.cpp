#include<bits/stdc++.h>
using namespace std;


vector<int> getSpanDays(vector<int> prices){
    vector<int> ans;
    stack<pair<int, int>> pds;
    
    for(int i = 0; i < prices.size(); i++){
        int days = 1;
       
        while(!pds.empty() && pds.top().first <= prices[i]){
            days += pds.top().second;
            pds.pop();
        }
        pds.push({prices[i], days});
        ans.push_back(days);
    }

    return ans;
}

int main(){
    vector<int> prices = {100,80,60,70,60,75,85};
    vector<int> ans;
    ans = getSpanDays(prices);

    for(auto  i:ans){
        cout << i <<  " ";
    }
    cout << endl;

    return 0;
}