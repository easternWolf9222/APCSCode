// 最短距離一定是所有邊長和的兩倍
// dfs路徑即字典排序路徑
// 因為沒有環路，不用考慮visited


#include <bits/stdc++.h>
using namespace std;

int n, t1, t2, total = 0;
vector<int> adj[50010];
vector<int> tour;

void dfs(int s, int come){
    tour.push_back(s);
    for(int v : adj[s]){
        if(v != come){
            dfs(v, s);
            tour.push_back(s);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n-1 ; i++){
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
        cin >> t1;
        total += t1;
    }

    for(int i = 0 ; i < n ; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(0, -1);

    cout << total * 2 << endl;

    int k = tour.size();
    for(int i = 0 ; i < k-1 ; i++){
        cout << tour[i] << " ";
    }
    cout << tour[k-1] << endl;

    return 0;
}
