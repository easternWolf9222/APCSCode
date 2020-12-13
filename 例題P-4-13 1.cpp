#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, a[100010], b[100010] = {0}, minimum = 10000000000000, maxSum = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }

    for(int i = 0 ; i < n+1 ; i++){
        if(b[i] < minimum)
            minimum = b[i];
        if(b[i] - minimum > maxSum)
            maxSum = b[i] - minimum;
    }

    cout << maxSum << endl;

    return 0;
}
