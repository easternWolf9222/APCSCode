#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, k, tmp;
    int a[200010];
    queue<int> q;
    q.push(-1);
    cin >> n >> k;
    for(int i = 0 ; i<n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
            tmp = 0;
        for(int j = i ; j < n ; j ++){
            tmp += a[j];

            if(tmp >= q.back() && tmp <= k){
                while(!q.empty() && q.front() != tmp)
                    q.pop();
                q.push(tmp);
            }

            if(tmp > k)
                break;
        }
    }
    cout << q.front() << endl;
    int cnt = 0;

    while(!q.empty()){
        cnt++;
        q.pop();
    }

    cout << cnt << endl;

    return 0;
}
