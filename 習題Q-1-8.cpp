#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

long long n, p, a[26];
long long ans = -1;

void r(int j, long long num){
    if(j == n){
        if(num < p && num > ans)
        ans = num;
    }else{
        r(j+1, num + a[j]);
        r(j+1, num);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> p;
    
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    
    r(0, 0);
    
    cout << ans << endl;
    
    return 0;
}
