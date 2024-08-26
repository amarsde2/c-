#include<bits/stdc++.h>
using namespace std;

struct node {
   int value;
   char letter;
};

vector<int>use(10);

int isValid(struct node *nodelist, const int count, string s1, string s2, string s3) {
    int val1 = 0, val2 = 0, val3 = 0,m = 1, i, j;
    for(i = s1.length()-1; i >= 0; i--){
        char ch = s1[i];
        for(j = 0; j < count; j++){
            if(nodelist[j].letter == ch){
                break;
            }
        }
        val1 += m * nodelist[j].value;
        m *= 10;
    }

    m = 1; 
    
    for(i = s2.length()-1; i >= 0; i--){
        char ch = s2[i];
        for(j = 0; j < count; j++){
            if(nodelist[j].letter == ch){
                break;
            }
        }
        val2 += m * nodelist[j].value;
        m *= 10;
    }

    m = 1;

    for(i = s3.length()-1; i >= 0; i--){
        char ch = s3[i];
        for(j = 0; j < count; j++){
            if(nodelist[j].letter == ch){
                break;
            }
        }
        val3 += m * nodelist[j].value;
        m *= 10;
    }

    if( val3 == (val1 + val2)){
        return 1;
    }

    return 0;

}

bool permuation(int count, struct node *nodelist, int n, string s1, string s2, string s3 ){
    if(n == count-1){
        for(int i = 0; i < 10; i++){
            if(use[i] == 0){
                nodelist[n].value = i;
                if(isValid(nodelist, count, s1, s2, s3) == 1){
                    cout << "Solution found " << endl;
                    for(int j = 0; j < count; j++){
                        cout << nodelist[j].letter << nodelist[j].value << endl;
                    }
                    return true;
                }
            }
        }
        return false;
    }

    for(int i = 0; i < 10; i++){
        if(use[i] == 0){
            nodelist[n].value = i;
            use[i] = 1;    
            if(permuation(count, nodelist, n + 1, s1, s2, s3)){
                return true;
            }
            use[i] = 0;
        }
    }

    return false;

}


bool solveCyptro(string s1, string s2, string s3){
    vector<int> freq(26);
    int uniquechar = 0;

    for(int i=0; i< s1.length(); i++){
        ++freq[s1[i] - 'A'];
    }

    for(int i=0; i< s2.length(); i++){
        ++freq[s2[i] - 'A'];
    }

    for(int i=0; i< s3.length(); i++){
        ++freq[ s3[i] - 'A'];
    }

    for(int i = 0 ; i < 26; i++){
        if(freq[i] > 0){
            uniquechar++;
        }
    }

    if(uniquechar > 10){

        cout << "Solution des not existe" << endl;
        return false;
    }

 
    struct node nodelist[uniquechar];
    
    for(int i = 0, j = 0; i < 26 ; i++){
        if(freq[i] > 0){
            nodelist[j].letter = char(i + 'A');
            j++;
        }
    }


    return permuation(uniquechar, nodelist, 0, s1, s2, s3);
}

int main(){
    string s1 = "BASE";
    string s2 = "BALL";
    string s3 = "GAMES";

    if(solveCyptro(s1, s2, s3) == false){
        cout << "No solution" << endl;
        return 0;
    }
}