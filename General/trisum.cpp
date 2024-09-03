#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n; 
    int total;
    cin >> total;
    vector<int> a(n);

    for(auto &i : a){
        cin >> i;
    }

    sort(a.begin(), a.end());
    bool flag = false;

    for(int i = 0; i < a.size(); i++){
        int low = i+1, high = n - 1;
        int current = 0;
        while(low < high){
            current = a[i] + a[low] + a[high];
            if(current == total){
                flag = true;
                break;
            } else if(current < total){
                low++;
            } else{
                high--;
            }
        }
        if(flag == true){
            break;
        }
    }
    
    if(flag == true){
        cout << "Find " << endl;
    } else{
        cout << "Not found " << endl;

        
    }

    return 0;
    
}