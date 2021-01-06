#include <bits/stdc++.h>
using namespace std;
int board[13][13], n, maxi = 0;

void f(int column, int q[], int sum){
    if(column >= n){
        maxi = max(maxi, sum);
        return;
    }

    f(column + 1, q, sum);

    bool invalid[13] = {0};

    for(int j = 0 ; j < column ; j++){
        if(q[j] != -1){
            invalid[q[j]] = 1;
            if(q[j]-(column-j) >= 0)
                invalid[q[j]-(column-j)] = 1;
            if(q[j]+(column-j) < n)
                invalid[q[j]+(column-j)] = 1;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(!invalid[i]){
            q[column] = i;
            f(column+1, q, sum+board[column][i]);
            q[column] = -1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> board[j][i];
        }
    }

    int queen[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    f(0, queen, 0);

    cout << maxi << endl;

    return 0;
}
