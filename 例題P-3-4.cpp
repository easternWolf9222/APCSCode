#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(0);

    int n;
    int a[210000];
    stack<int> s;
    long long sum = 0;
    a[0] = 10000010;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i+1];
    }

    s.push(0);
    for(int i = 1; i <= n ; i++){
        while(a[i] >= a[s.top()]){
            s.pop();
        }
        sum += i - s.top();
        s.push(i);
    }
    cout << sum << endl;

    return 0;

}
