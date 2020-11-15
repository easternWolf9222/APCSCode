#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int ans = 9999999;

int h, w;
int a[12][12];
int sum;

void r(int U, int D, int L, int R, int cost){
    if(U == D || L == R){
        if(cost < ans)
            ans = cost;
    }else{
        //去掉上
        sum = 0;
        for(int k = L ; k <= R ; k++)
            sum += a[U][k]; //求得1的數量
        if(sum <= (R - L + 1) - sum)
            r(U+1, D, L, R, cost + sum);
        else
            r(U+1, D, L, R, cost + (R - L + 1) - sum);
        
        //去掉下
        sum = 0;
        for(int k = L ; k <= R ; k++)
            sum += a[D][k]; //求得1的數量
        if(sum <= (R - L + 1) - sum)
            r(U, D-1, L, R, cost + sum);
        else
            r(U, D-1, L, R, cost + (R - L + 1) - sum);
       
        //去掉左
        sum = 0;
        for(int k = U ; k <= D ; k++)
            sum += a[k][L]; //求得1的數量
        if(sum <= (D - U + 1) - sum)
            r(U, D, L+1, R, cost + sum);
        else
            r(U, D, L+1, R, cost + (D - U + 1) - sum);
        
        //去掉右
        sum = 0;
        for(int k = U ; k <= D ; k++)
            sum += a[k][R]; //求得1的數量
        if(sum <= (D - U + 1) - sum)
            r(U, D, L, R-1, cost + sum);
        else
            r(U, D, L, R-1, cost + (D - U + 1) - sum);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> h >> w;
    for(int i = 0 ; i < h ; i++)
        for(int j = 0 ; j < w ; j++)
            cin >> a[i][j];
    
    r(0, h-1, 0, w-1, 0);
    
    cout << ans << endl;
    
    return 0;
}
