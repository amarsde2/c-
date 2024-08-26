#include<bits/stdc++.h>
using namespace std;

struct Suffix {
    int index;
    string suffix;
};

bool compareFun(Suffix a, Suffix b) {
   return a.suffix < b.suffix;
}

int * generateSuffix(string text, int n){
    Suffix *suffix = new Suffix[n];
    for(int i = 0; i < n; i++){
        suffix[i].index = i;
        suffix[i].suffix = text.substr(i , n-1);
    }
    
    sort(suffix, suffix + n, compareFun);

    int *suffixArray = new int[n];

    for(int i = 0; i < n; i++){
        suffixArray[i] = suffix[i].index;
    }



    delete[] suffix;
    return suffixArray;
}

void searchPattern(int Suffix[], string pat, string txt, int n){
    int l = 0 , r = n-1;
    int m = pat.length();

    while(l < r){
        int mid = (r - l)/ 2;
        string substr = txt.substr(Suffix[mid], m);
        if(substr == pat){
            cout << "Pattern found at index " << Suffix[mid] << endl;

            int temp = mid -1;
            while(temp > 0 && txt.substr(Suffix[temp], m) == pat){
                cout << "Pattern found at index" << Suffix[temp] << endl;
                temp--;
            }

            temp = mid + 1;
            while(temp < n && txt.substr(Suffix[temp], m) == pat){
                cout << "Pattern found at index" << Suffix[temp] << endl;
                temp++;
            }
            return;
        } else{
            if( pat < substr) {
                r = mid -1; 
            } else{
                l = mid + 1;
            }
        }
    }

    cout << "Pattern not found" << endl;
}

int main(){
   string txt = "AAAABCAEAAABCBDDAAAABC";
   string pat = "AAABC";
   int n = txt.length();
   int *sufficeArray = generateSuffix(txt, n);
   searchPattern(sufficeArray, pat,txt, n);
   delete [] sufficeArray;
   return 0;
}