#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, mini = 100010, x, y, tmpx, tmpy, sum = 0;
    int grid[102][102];
    bool visited[102][102] = {0};
    cin >> m >> n;

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> grid[j][i];
            if(grid[j][i] < mini){
                mini = grid[j][i];
                x = j;
                y = i;
            }
        }
    }
    for(int i = 0 ; i <= m+1 ; i++){
        visited[0][i] = 1;
        visited[n+1][i] = 1;
    }
    for(int i = 0 ; i <= n+1 ; i++){
        visited[i][0] = 1;
        visited[i][m+1] = 1;
    }

    visited[x][y] = 1;
    sum = mini;
    mini = 100011;
    while(mini != 100010){
        mini = 100010;
        if(!visited[x-1][y] && grid[x-1][y] < mini){
            mini = grid[x-1][y];
            tmpx = x-1;
            tmpy = y;
        }
        if(!visited[x+1][y] && grid[x+1][y] < mini){
            mini = grid[x+1][y];
            tmpx = x+1;
            tmpy = y;
        }
        if(!visited[x][y-1] && grid[x][y-1] < mini){
            mini = grid[x][y-1];
            tmpx = x;
            tmpy = y-1;
        }
        if(!visited[x][y+1] && grid[x][y+1] < mini){
            mini = grid[x][y+1];
            tmpx = x;
            tmpy = y+1;
        }
        x = tmpx;
        y = tmpy;
        visited[x][y] = 1;
        sum += mini;
    }

    cout << sum - 100010 << endl;



    return 0;
}
