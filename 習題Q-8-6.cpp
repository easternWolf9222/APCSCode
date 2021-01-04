#include <bits/stdc++.h>
using namespace std;
long long n, k, sum = 0, w[100010];
vector<int> child[100010];


long long dfs(int s){
    long long t = 0;
    for(int v : child[s]){
        t += dfs(v) + 1;
    }

    if(s != 1){
        sum += w[s] * (t+1) * (n-t-1);
    }

    return t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 2 ; i <= n ; i++){
        cin >> k;
        child[k].push_back(i);
    }
    for(int i = 2 ; i <= n ; i++)
        cin >> w[i];

    k = dfs(1);

    cout << sum*2 << endl;

    return 0;
}
