//貪心演算法要注意證明

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, op[200020], us[200020], cnt = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> op[i];
    for(int i = 0 ; i < n ; i++)
        cin >> us[i];
    sort(op, op+n);
    sort(us, us+n);

    int weakOp = 0;
    for(int i = 0 ; i < n ; i++){
        if(us[i] > op[weakOp]){
            weakOp++;
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
