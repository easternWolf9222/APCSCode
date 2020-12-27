#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char a[505], b[505];
    int dp1[505] = {0}, dp2[505];
    cin >> a >> b;
    int la = strlen(a), lb = strlen(b);
    for(int i = 1 ; i <= la ; i++){
        for(int j = 0 ; j <= lb ; j++){
            if(j == 0)
                dp2[j] = 0;
            else if(a[i-1] == b[j-1])
                dp2[j] = dp1[j-1] + 1;
            else
                dp2[j] = max(dp1[j], dp2[j-1]);
        }
        for(int j = 0 ; j <= lb ; j++){
            dp1[j] = dp2[j];
        }
    }

    cout << dp2[lb] << endl;

    return 0;
}
