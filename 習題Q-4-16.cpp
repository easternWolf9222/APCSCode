#include <bits/stdc++.h>
using namespace std;
int n, m, p[100010], maxi = 0, sum = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    pair<int, int> a[100010];
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].first;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].second;

    sort(a, a+n);

    long long t = 0, sum = 0;
    for(int i = 0 ; i < n ; i++){
        t += a[i].first;
        sum += a[i].second-t;
    }

    cout << sum << endl;

    return 0;
}
