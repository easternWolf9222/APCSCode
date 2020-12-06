//釐清思路

#include <bits/stdc++.h>
using namespace std;

int n, k;
int x[100000];

int seg(int l){ //特定基地台半徑要完全覆蓋的最少段數
    int cnt = 0;
    int i = 0;
    while(i < n){
        cnt++;
        int tmp = x[i] + l;

        i++;
        while(i < n && x[i] <= tmp){
            i++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        cin >> x[i];
    }
    sort(x, x+n);
    int a = 0, b = x[n-1]-x[0];


    int p = 0;
    for(int jump = (b-a)/2 ; jump > 0 ; jump >>= 1){ //跳躍式二分搜
        while(p + jump <= b && seg(p + jump) > k){
            p += jump;
        }
    }

    cout << p+1 << endl;
    return 0;
}
