//Let me die...

#include <bits/stdc++.h>
using namespace std;
long long dp[20][11] = {0};

//number of "stair numbers" that have n digits, start with k.
long long cnt(int n, int k){
    if(n == 1 && k == 0)
        return 0;

    if(dp[n][k] > 0)
        return dp[n][k];

    if(n == 1){
        dp[n][k] = 1;
        return 1;
    }

    long long tmp = 0;
    for(int i = k; i <= 9 ; i++)
        tmp += cnt(n-1, i);
    dp[n][k] = tmp;
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int digit[20] = {0};
    long long n, ans = 0;
    cin >> n;

    int k = 1;
    while(n > 0){
        digit[k] = n%10;
        n /= 10;
        k++;
    }
    k--;

    int flag = 0;
    for(int i = k ; i >= 1 ; i--){
        if(digit[i] < digit[i+1]){
            flag = 1;
            break;
        }
        for(int j = digit[i+1] ; j < digit[i] ; j++){
            ans += cnt(i, j);
        }
    }
    if(flag == 0)
        ans++;

    cout << ans << endl;
    return 0;
}
