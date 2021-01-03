#include <bits/stdc++.h>
using namespace std;

int n, t1, t2;
vector<pair<int, int>> child[100010];

int dfs(int s){
    int maxi = 0, t;
    for(auto v : child[s]){
        t = dfs(v.first);
        maxi = max(maxi, v.second + t);
    }
    return maxi;
}

int dfs2(int s){
    int maxi = 0, t;
    for(auto v : child[s]){
        t = dfs2(v.first);
        maxi = max(maxi, 1 + t);
    }
    return maxi;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1 ; i < n ; i++){
        cin >> t1 >> t2;
        child[t1].push_back({i, t2});
    }

    cout << dfs(0) << endl << dfs2(0) << endl;

    return 0;
}
