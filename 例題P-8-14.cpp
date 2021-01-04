#include <bits/stdc++.h>
using namespace std;

int parent[100010], n, t1, t2, root, ans = 0;
vector<int> child[100010];

int dfs(int s){
    int max1 = 0, max2 = 0, t = 0, h = 0;
    for(int v : child[s]){
        t = dfs(v) + 1;

        if(t > max1){
            max2 = max1;
            max1 = t;
        }else if(max1 >= t && t > max2){
            max2 = t;
        }
        ans = max(ans, max1+max2);
        h = max(h, t);
    }
    return h;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 0 ; i < n ; i++)
        parent[i] = -1;
        
    for(int i = 0 ; i < n-1 ; i++){
        cin >> t1 >> t2;
        parent[t2] = t1;
        child[t1].push_back(t2);
    }
    for(int i = 0 ; i < n ; i++){
        if(parent[i] == -1)
            root = i;
    }

    int r = dfs(root);

    cout << ans << endl;
    return 0;
}
