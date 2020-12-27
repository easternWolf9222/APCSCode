#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, p[100050], dp[100050];
    cin >> n >> k;

    for(int i = 1 ; i <= n ; i++)
        cin >> p[i];
    
    //Initial values
    dp[0] = 0;
    dp[1] = p[1];
    for(int i = 2 ; i <= k+1 ; i++)
        dp[i] = max(dp[i-1], p[i]);

    //Bottom up
    for(int i = k+2 ; i <= n ; i++)
        dp[i] = max(p[i] + dp[i-k-1] , dp[i-1]);


    cout << dp[n] << endl;

    return 0;
}
