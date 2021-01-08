#include <bits/stdc++.h>
using namespace std;
int n, m, p[100010], maxi = 0, sum = 0;

int f(int s){
    int F = s;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(F-p[i] < 0){
            cnt++;
            F = s;
        }
        F -= p[i];
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
        maxi = max(maxi, p[i]);
        sum += p[i];
    }

    int pos = maxi;
    int step = (sum - maxi + 1)/2;
    if(f(maxi) <= m){
        pos--;
    }else{
        while(step > 0){
            if(pos + step <= sum && f(pos + step) > m)
                pos += step;
            step /= 2;
        }
    }

    cout << pos+1 << endl;

    return 0;
}
