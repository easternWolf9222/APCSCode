#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, tmp1, tmp2, sum = 0, cnt = 0;
    vector<int> adj[100];
    bool visited[100] = {0};
    int d[100] = {0};
    queue<int> q;
    cin >> n >> m;
    cin >> s;
    for(int i = 0 ; i < m ; i++){
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
    }
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        tmp1 = q.front();  //back in front out
        for(int i : adj[tmp1]){
            if(!visited[i]){
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
