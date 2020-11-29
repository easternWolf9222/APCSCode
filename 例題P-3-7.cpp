#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k, tmp, maxi = -1, cnt = 0;
    int a[200010];
    cin >> n >> k;
    for(int i = 0 ; i<n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
            tmp = 0;
        for(int j = i ; j < n ; j ++){
            tmp += a[j];

            if(tmp > maxi && tmp <= k){
                maxi = tmp;
                cnt = 1;
            }else if(tmp == maxi){
                cnt++;
            }

            if(tmp > k)
                break;
        }
    }

    cout << maxi << endl << cnt << endl;

    return 0;
}
