#include <bits/stdc++.h>
using namespace std;
int cost[205][205] = {0};
int n, L, a[205];

int c(int s, int t){
    if(s+1 == t)
        return 0;

    if(cost[s][t] > 0)
        return cost[s][t];


    int tmp = 1000000000;
    for(int i = s+1 ; i <= t-1 ; i++){
        tmp = min(tmp, c(s,i) + c(i,t) + a[t] - a[s]);
    }
    cost[s][t] = tmp;
    return tmp;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> L;
    a[0] = 0;
    a[n+1] = L;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];

    cout << c(0, n+1) << endl;

    return 0;
}
