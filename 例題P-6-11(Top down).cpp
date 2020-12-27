#include <bits/stdc++.h>
using namespace std;

long long a[105] = {1};
bool calced[105] = {1};

long long cat(int n){
    if(calced[n])
        return a[n];

    for(int j = 0 ; j <= n-1 ; j++){
        a[n] += (cat(j) * cat(n-1-j)) % 1000000009;
    }
    a[n] %= 1000000009;
    calced[n] = true;
    return a[n];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cout << cat(N) << endl;

    return 0;
}
