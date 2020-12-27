#include <bits/stdc++.h>
using namespace std;
int dp[200][200] = {0};
int a[205];

int f(int s, int t){
    if(dp[s][t] > 0)
        return dp[s][t];

    if(s+1 == t)
        return 0;

    int m = 99999999;
    for(int i = s+1 ; i <= t-1 ; i++)
        m = min(m, a[s] * a[i] * a[t] + f(s,i) + f(i,t));
    dp[s][t] = m;
    return m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0 ; i <= n ; i++)
        cin >> a[i];

    cout << f(0, n) << endl;

    return 0;
}
