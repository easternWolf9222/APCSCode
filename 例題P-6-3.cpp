#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int p[100010];

    cin >> n;
    for(int i = 1 ; i < n+1 ; i++){
        cin >> p[i];
    }

    int a = p[1];
    int b = p[2];
    int c = p[3] + min(p[1], p[2]);
    int tmp, tmp2;

    for(int i = 4 ; i < n+1 ; i++){
        tmp = min(p[i] + a, min(p[i] + b, p[i] + c));
        a = b;
        b = c;
        c = tmp;
        if(i == n-1)
            tmp2 = tmp;
    }

    cout << min(tmp,tmp2) << endl;

    return 0;
}
