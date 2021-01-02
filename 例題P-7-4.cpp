#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, dis[510][510];
    bool grid[510][510];
    char t[501];

    cin >> m >> n;

    for(int i = 0 ; i <= n+1 ; i++){
        grid[i][0] = 1;
        grid[i][m+1] = 1;
    }
    for(int i = 0 ; i <= m+1 ; i++){
        grid[0][i] = 1;
        grid[n+1][i] = 1;
    }
    for(int i = 1 ; i <= m ; i++){
        cin >> t;
        for(int j = 0 ; j < n ; j++)
            grid[j+1][i] = t[j] - '0';
    }

    for(int i = 0 ; i <= m+1 ; i++){
        for(int j = 0 ; j <= n+1 ; j++)
            dis[j][i] = -1; //not visited
    }

    queue<pair<int, int>> q;

    q.push({1,1});
    int x, y, tmpx, tmpy;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        tmpx = x+1;
        tmpy = y;
        while(dis[tmpx][tmpy] == -1 && grid[tmpx][tmpy] == 0){
            q.push({tmpx, tmpy});
            dis[tmpx][tmpy] = dis[x][y] + 1;
            tmpx++;
        }

        tmpx = x-1;
        tmpy = y;
        while(dis[tmpx][tmpy] == -1 && grid[tmpx][tmpy] == 0){
            q.push({tmpx, tmpy});
            dis[tmpx][tmpy] = dis[x][y] + 1;
            tmpx--;
        }

        tmpx = x;
        tmpy = y+1;
        while(dis[tmpx][tmpy] == -1 && grid[tmpx][tmpy] == 0){
            q.push({tmpx, tmpy});
            dis[tmpx][tmpy] = dis[x][y] + 1;
            tmpy++;
        }

        tmpx = x;
        tmpy = y-1;
        while(dis[tmpx][tmpy] == -1 && grid[tmpx][tmpy] == 0){
            q.push({tmpx, tmpy});
            dis[tmpx][tmpy] = dis[x][y] + 1;
            tmpy--;
        }
    }

//    for(int i = 1 ; i <= m ; i++){
//        for(int j = 1 ; j <= n ; j++)
//            cout << dis[j][i] << "\t ";
//        cout << endl;
//    }

    cout << dis[n][m] << endl;


    return 0;
}
