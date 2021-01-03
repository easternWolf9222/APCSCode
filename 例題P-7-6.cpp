#include <bits/stdc++.h>
using namespace std;

int n, m, t1, t2, t3, s, t;
vector<pair<int, int>> adj[10010];
int d[10010];
int visited[10010] = {0};

int f_min(int p){
    if(visited[p]){
        return d[p];
    }

    if(p == s){
        visited[s] = 1;
        return 0;
    }

    int tmp = INT_MAX;
    for(auto v : adj[p]){
        if(f_min(v.first) != INT_MAX && v.second + f_min(v.first) < tmp)
            tmp = v.second + f_min(v.first);
    }

    visited[p] = 1;
    d[p] = tmp;

    return tmp;
}

int f_max(int p){
    if(visited[p]){
        return d[p];
    }

    if(p == s){
        visited[s] = 1;
        return 0;
    }

    int tmp = -INT_MAX;
    for(auto v : adj[p]){
        if(f_max(v.first) != -INT_MAX && v.second + f_max(v.first) > tmp)
            tmp = v.second + f_max(v.first);
    }

    visited[p] = 1;
    d[p] = tmp;

    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    cin >> s >> t;
    for(int i = 0 ; i < m ; i++){
        cin >> t1 >> t2 >> t3;
        adj[t2].push_back({t1, t3});
    }
    d[s] = 0;

    int minimum = f_min(t);

    if(visited[s]){
        for(int i = 0 ; i < n ; i++){
            visited[i] = 0;
        }
        cout << minimum << endl << f_max(t) << endl;
    }else{
        cout << "No path\nNo path\n";
    }


    return 0;
}
