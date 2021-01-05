#include <bits/stdc++.h>
using namespace std;

int n, m, t1, t2, ans = 0, x, dp[1010][4];
string seq[1010];
vector<int> child[1010];

int ctoi(char a){
    if(a == 'A')
        return 0;
    if(a == 'U')
        return 1;
    if(a == 'G')
        return 2;
    if(a == 'C')
        return 3;
}



int f(int s, int code){
//    if(dp[s][code] != -1)
//        return dp[s][code];

    int t, sum = 0;
    for(int v : child[s]){
        t = INT_MAX;
        if(seq[v][x] == '@'){
            t = min(t, f(v, 0) + (code != 0));
            t = min(t, f(v, 1) + (code != 1));
            t = min(t, f(v, 2) + (code != 2));
            t = min(t, f(v, 3) + (code != 3));
        }else{
            t = f(v, ctoi(seq[v][x])) + (code != ctoi(seq[v][x]));
        }
        sum += t;
    }
    //dp[s][code] = sum;
    return sum;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        cin >> t1 >> t2;
        if(t1 != t2){
            child[t2].push_back(t1);
        }
        cin >> seq[t1];
    }


    for(x = 0 ; x < m ; x++){
//        for(int i = 1 ; i <= n ; i++){
//            for(int j = 0 ; j <= 3 ; j++)
//                dp[i][j] = -1;
//        }
        if(seq[1][x] == '@')
            ans += min(f(1,0),min(f(1,1),min(f(1,2),f(1,3))));
        else
            ans += f(1,ctoi(seq[1][x]));
    }

    cout << ans << endl;


    return 0;
}
