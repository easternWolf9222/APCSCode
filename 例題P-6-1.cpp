#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int c[100010];
    cin >> n;

    for(int i = 1 ; i < n+1 ; i++){
        cin >> c[i];
    }

    int a = c[1];
    int b = c[2];
    int tmp;

    for(int i = 3 ; i < n+1 ; i++){
        tmp = c[i] + min(a, b);
        a = b;
        b = tmp;
    }

    cout << tmp << endl;

    return 0;
}
