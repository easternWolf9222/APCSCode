#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, dp1[100010] = {0}, dp2[100010], p[100010], prefixMaxi[100010] = {0}, prefixMaxi2[100010] = {0};

    cin >> n >> k;

    int t1, t2;
    cin >> t1;
    for(int i = 1 ; i < n ; i++){
        cin >> t2;
        p[i] = t2 - t1;
        t1 = t2;
    }

    for(int i = 1 ; i <= k ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0)
                dp2[j] = 0;
            else
                dp2[j] = max(dp2[j-1] + p[j], prefixMaxi[j-2] + p[j]);
                prefixMaxi2[j] = max(prefixMaxi2[j-1] , dp2[j]);

        }
        for(int j = 0 ; j < n ; j++){
            dp1[j] = dp2[j];
            prefixMaxi[j] = prefixMaxi2[j];
        }
    }

    int maxi = 0;
    for(int i = 0 ; i < n ; i++){
        if(dp2[i] > maxi)
            maxi = dp2[i];
    }
    cout << maxi << endl;
    return 0;
}
