#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int p[100010];

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
    }

    int a = p[0];
    int b = max(p[0], p[1]);
    int tmp;

    for(int i = 2 ; i < n ; i++){
        tmp = max(p[i] + a, b);
        a = b;
        b = tmp;
    }

    cout << tmp << endl;

    return 0;
}
