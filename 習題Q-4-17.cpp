#include <bits/stdc++.h>
using namespace std;
int n, m, p[100010], maxi = 0, sum = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, n;
    pair<int, int> a[100010];
    cin >> N;
    for(int v = 0 ; v < N ; v++){
        cin >> n;

        for(int i = 0 ; i < n ; i++)
            cin >> a[i].second;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i].first;

        sort(a, a+n);

        long long t = 0;
        bool ok = true;
        for(int i = 0 ; i < n ; i++){
            t += a[i].second;
            if(t > a[i].first){
                ok = false;
                break;
            }
        }

        if(ok)
            cout << "yes\n";
        else
            cout << "no\n";
    }


    return 0;
}
