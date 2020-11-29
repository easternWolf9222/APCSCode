#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, k, tmp, maxi = -1, cnt = 0;
    int a[200010];
    cin >> n >> k;
    for(int i = 0 ; i<n ; i++){
        cin >> a[i];
    }
    int left = 0, right = 0;
    tmp = 0;
    for(right = 0 ; right <= n-1 ; right++){ //one right end only has one possible answer, because theres no zero.
        tmp += a[right];

        while(tmp > k){
            left++;
            tmp -= a[left-1];
        }
        if(tmp > maxi){
            maxi = tmp;
            cnt = 1;
        }else if(tmp == maxi)
            cnt++;

    }


    cout << maxi << endl << cnt << endl;

    return 0;
}
