// Example program
#include <bits/stdc++.h>

using namespace std;

long long n, l;
long long a[100000];
long long cnt = 0;

void cut(int start , int end){
    if(end - start > 1){
        cnt += a[end] - a[start];
        long long mid = (a[start]+a[end])/2;
        int x = lower_bound(a+start, a+end, mid)-a;
        if(a[end]-a[x] > a[x-1]-a[start]){
            cut(start, x);
            cut(x, end);
        }else if(a[end]-a[x] < a[x-1]-a[start]){
            cut(start, x-1);
            cut(x-1, end);
        }else{
            cut(start, x-1);
            cut(x-1, end);
        }
    }
    
}


int main()
{
    cin >> n >> l;
    a[0] = 0;
    a[n+1] = l;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i+1];
    }
    
    cut(0, n+1);
    cout << cnt << endl;
    return 0;
}
