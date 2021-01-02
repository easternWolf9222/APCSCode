#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, tmp1, tmp2, sum = 0, cnt = 0;
    bool edge[100][100] = {0};
    bool visited[100] = {0};
    int d[100] = {0};
    queue<int> q;
    cin >> n >> m;
    cin >> s;
    for(int i = 0 ; i < m ; i++){
        cin >> tmp1 >> tmp2;
        edge[tmp1][tmp2] = 1;
    }
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        tmp1 = q.front();  //back in front out
        for(int i = 0 ; i < n ; i++){
            if(!visited[i] && edge[tmp1][i]){
                q.push(i);
                visited[i] = 1;
                d[i] = d[tmp1] + 1;
                cnt++;
                sum += d[i];
            }
        }
        q.pop();
    }
    cout << cnt << endl << sum << endl;
    return 0;
}
