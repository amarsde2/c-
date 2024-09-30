#include<bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &a, int x, int y){
    a[x][y] = '*';
    int dx[] = {0 , 0 ,-1,1};
    int dy[] = {1, -1, 0, 0};

    for(int i = 0; i < 4; i++){
        x = x + dx[i];
        y = y + dy[i];
        if(x >= 0 && y>=0 && x <= a.size() && y <= a[0].size() && a[x][y] == 'o'){
           change(a, x, y);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if( i== 0 || i == n-1 || j == 0 || j == m-1){
                if(a[i][j] == 'o'){
                    change(a, i, j);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'o'){
               a[i][j] = 'x'; 
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '*'){
               a[i][j] = 'o'; 
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}