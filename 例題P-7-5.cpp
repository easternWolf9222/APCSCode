#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, l, r, t;
    int s[1000010];
    int d[1000010];
    cin >> n >> p >> l >> r;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
        d[i] = -1;
    }

    queue<int> q;
    q.push(0);

    d[0] = 0;
    while(!q.empty()){
        t = q.front();
        q.pop();

        if(t-l >= 0){
            if(s[t-l] >= 0 && s[t-l] <= n-1 && d[s[t-l]] == -1){
                q.push(s[t-l]);
                d[s[t-l]] = d[t] + 1;
            }
        }

        if(t+r <= n-1){
            if(s[t+r] >= 0 && s[t+r] <= n-1 && d[s[t+r]] == -1){
                q.push(s[t+r]);
                d[s[t+r]] = d[t] + 1;
            }
        }
    }

    cout << d[p] << endl;

    return 0;
}
