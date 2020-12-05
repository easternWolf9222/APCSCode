#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans = 0, g = 0;
    int a[200010], label[200010] = {0};
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }

    int s = 0 , t = 0;
    g = 1;
    label[a[0]] = 1;
    while(t < n-1){
        while(g == t-s+1 && t != n-1){
            t++;
            label[a[t]]++;
            if(label[a[t]] == 1)
                g++;
        }

        if(g > ans)
            ans = g;
            
        s++;
        label[a[s-1]]--;
        if(label[a[s-1]] == 0)
            g--;
    }

    cout << ans << endl;

    return 0;
}
