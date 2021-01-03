#include <bits/stdc++.h>
using namespace std;

int visited[10010] = {0};
vector<int> adj[10010];
int t, n = 0, m, t1, t2;
bool ans = 1;

bool dfs(int s, int color){
    visited[s] = color;
    bool flag = 1;
    for(int v : adj[s]){
        if(visited[s] == visited[v]){ //same color
            return 0;
        }
        if(visited[v] == 0){
            flag &= dfs(v, -visited[s]);
        }
    }
    return flag;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int i = 0 ; i < t ; i++){
        for(int j = 0 ; j < n ; j++){
            adj[j].clear();
            visited[j] = 0;
        }
        ans = 1;

        cin >> n >> m;
        for(int j = 0 ; j < m ; j++){
            cin >> t1 >> t2;
            adj[t1].push_back(t2);
            adj[t2].push_back(t1);
        }
        for(int j = 0 ; j < n ; j++){
            if(visited[j] == 0){
                if(dfs(j, 1) == 0){
                    ans = 0;
                    break;
                }
            }
        }
        if(ans)
            cout << "yes\n";
        else
            cout << "no\n";
    }



    return 0;
}
