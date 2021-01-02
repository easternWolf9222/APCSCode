#include <bits/stdc++.h>
using namespace std;

int n, m, t1, t2, maxi = -1;
int value[50050];
bool visited[50050] = {0};
vector<int> adj[50050];

int dfs(int s){
    int sum = value[s];
    visited[s] = 1;
    for(int v : adj[s]){
        if(!visited[v])
            sum += dfs(v);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> value[i];
    }
    for(int i = 0 ; i < m ; i++){
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }

    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
             t1 = dfs(i);
             if(t1 > maxi)
                maxi = t1;
        }
    }
    cout << maxi << endl;

    return 0;
}
