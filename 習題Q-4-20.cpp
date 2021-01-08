#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, t;
    pair<int, int> a[100010];
    cin >> n >> s >> t;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a+n);
    int maxi = -1, ans = 0, i = 0;

    while(s < t){
        while(a[i].first <= s){
            if(a[i].second > s)
                maxi = max(maxi, a[i].second);
            i++;
        }
        if(maxi == -1){
            ans = -1;
            break;
        }
        s = maxi;
        maxi = -1;
        ans++;
    }

    cout << ans << endl;

    return 0;
}
