#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long a[105] = {1};
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= i-1 ; j++){
            a[i] += (a[j] * a[i-1-j]) % 1000000009;
        }
        a[i] %= 1000000009;
    }

    cout << a[n] << endl;

    return 0;
}
