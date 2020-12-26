#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, a[100010], maxSum = 0, tmp = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    for(int i = 0 ; i < n ; i++){
        if(tmp <= 0)
            tmp = a[i];
        else
            tmp += a[i];
        if(tmp > maxSum)
            maxSum = tmp;
    }

    cout << maxSum << endl;
 
    return 0;
}
