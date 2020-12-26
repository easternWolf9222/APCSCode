#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    int f[110], prefix[110], dp1[200050], dp2[200050];
    cin >> n >> m >> s;

    prefix[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        cin >> f[i];
        prefix[i] = prefix[i-1] + f[i];
    }

    if(m-prefix[n] >= s){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0 ; i <= m ; i++){
        if(i == 0)
            dp1[i] = 0;
        else if(i <= f[1])
            dp1[i] = f[1];
        else
            dp1[i] = 300000;
    }

    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(j == 0)
                dp2[j] = 0;
            else if(prefix[i] < j)
                dp2[j] = 300000;
            else if(f[i] > j)
                dp2[j] = min(f[i], dp1[j]);
            else
                dp2[j] = min(f[i] + dp1[j-f[i]], dp1[j]);
        }
        for(int j = 0 ; j <= m ; j++){
            dp1[j] = dp2[j];
        }
    }

    cout << dp2[s-m+prefix[n]] << endl;

    return 0;
}
