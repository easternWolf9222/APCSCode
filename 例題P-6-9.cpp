#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, W;
    int p[1000], w[1000], dp1[100005], dp2[100005];
    cin >> n >> W;
    for(int i = 1 ; i <= n ; i++)
        cin >> w[i];
    for(int i = 1 ; i <= n ; i++)
        cin >> p[i];

    for(int i = 0 ; i <= W ; i++)
        dp1[i] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= W ; j++){
            if(j == 0)
                dp2[j] = 0;
            else if(w[i] > j)
                dp2[j] = dp1[j];
            else
                dp2[j] = max(p[i] + dp1[j-w[i]], dp1[j]);
        }
        for(int j = 0 ; j <= W ; j++)
            dp1[j] = dp2[j];
    }

    cout << dp2[W] << endl;

    return 0;
}
