#include <bits/stdc++.h>
using namespace std;
int p[26][26];
int dp[26][26][26][26];
bool calced[26][26][26][26] = {0};

int f(int L, int R, int U, int D){
    if(calced[L][U][R][D])
        return dp[L][U][R][D];

    if(R == L || U == D)
        return 0;

    int minimum;

    //remove U
    int tmp = 0;
    for(int i = L ; i <= R ; i++)
        tmp += p[i][U];
    if(tmp <= R-L+1-tmp)
        minimum = tmp + f(L, R, U+1, D);
    else
        minimum = R-L+1-tmp + f(L, R, U+1, D);

    //remove D
    tmp = 0;
    for(int i = L ; i <= R ; i++)
        tmp += p[i][D];
    if(tmp <= R-L+1-tmp)
        minimum = min(tmp + f(L, R, U, D-1), minimum);
    else
        minimum = min(R-L+1-tmp + f(L, R, U, D-1), minimum);

    //remove L
    tmp = 0;
    for(int i = U ; i <= D ; i++)
        tmp += p[L][i];
    if(tmp <= D-U+1-tmp)
        minimum = min(tmp + f(L+1, R, U, D), minimum);
    else
        minimum = min(D-U+1-tmp + f(L+1, R, U, D), minimum);

    //remove R
    tmp = 0;
    for(int i = U ; i <= D ; i++)
        tmp += p[R][i];
    if(tmp <= D-U+1-tmp)
        minimum = min(tmp + f(L, R-1, U, D), minimum);
    else
        minimum = min(D-U+1-tmp + f(L, R-1, U, D), minimum);

    dp[L][U][R][D] = minimum;
    calced[L][U][R][D] = true;
    return minimum;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> p[j][i];
        }
    }

    cout << f(0, n-1, 0, m-1) << endl;

    return 0;
}
