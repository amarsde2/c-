#include<bits/stdc++.h>
#include<vector>
using namespace std;


struct Suffix{
    int index;
    int rank[2];
};

bool compareFun(Suffix a, Suffix b){
    if(a.rank[0] == b.rank[0]){
        if(a.rank[1] < b.rank[1]){
            return true;
        } else{
            return false;
        }
    } else{
        if(a.rank[0] < b.rank[0]){
            return true;
        } else{
            return false;
        }
    }
}

vector<int> kasai(string text, vector<int> suffixArray){
    int n = suffixArray.size();
    vector<int> lsp(n,0);
    vector<int> suffixInverse(n,0);

    for(int i=0;i<n;i++){
        suffixInverse[suffixArray[i]] = i;
    }

    int k = 0;

    for(int i=0; i < n; i++){
        if(suffixInverse[i] == n-1){
            k = 0;
            continue;
        }

        int j = suffixArray[suffixInverse[i]+1];

        while(j + k < n  && i + k < n && text[j+k] == text[i+k]){
            k++;
        }

        lsp[suffixInverse[i]] = k;

        if(k > 0){
            k--;
        }
    }

    return lsp;
}

vector<int> generateSuffixArray(string text){
    int n = text.length();
    Suffix suffix[n];

    for(int i = 0 ; i < n ; i++){
        suffix[i].index = i;
        suffix[i].rank[0] = text[i] - 'a';
        suffix[i].rank[1] = i + 1 < n ? text[i+1] - 'a': -1;
    }

    sort(suffix , suffix+ n, compareFun);

    int index[n];

    for(int k = 4; k < n *2; k = k*2 ){
        int current = 0; 
        int prev = suffix[0].rank[0];
        suffix[0].rank[0] = current;
        index[suffix[0].index] = 0;

        for(int i = 1; i < n; i++){
            if(suffix[i].rank[0] == prev && suffix[i].rank[1] == suffix[i-1].rank[1]){
               prev = suffix[i].rank[0];
               suffix[i].rank[0] = current;
            } else{
                prev = suffix[i].rank[0];
                suffix[i].rank[0] = ++current;
            }
            index[suffix[i].index] = i;
        }

        for(int i = 0 ; i < n ; i++){
            int nextIndex = suffix[i].index + k/2;
            suffix[i].rank[1] = nextIndex < n ? suffix[index[nextIndex]].rank[0]  : -1; 
        }
        sort(suffix , suffix+ n, compareFun);
    }
    
    vector<int> SuffixArray;

    for(int i = 0; i < n; i++){
        SuffixArray.push_back(suffix[i].index);
    }
    return SuffixArray;
}

void display(vector<int> suffArray){
    vector<int>::iterator it;
    for(it= suffArray.begin(); it < suffArray.end(); it++){
        cout << *it << '\n';
    }
}
int main(){
    string text = "AAABCAEAAABCBDDAAAABC";

    vector<int> suffixArray = generateSuffixArray(text);

    display(suffixArray);

    cout << "Suffix Array: " <<  endl;

    vector<int> lsp = kasai(text,suffixArray);

    display(lsp);

    return 0;

}