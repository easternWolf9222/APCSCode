#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>

#define m 1000000007

using namespace std;

struct Matrix{
    long long a, b, c, d;
};

Matrix mult(Matrix A, Matrix B){
    Matrix R;
    R.a = (A.a%m * B.a%m + A.b%m * B.c%m)%m;
    R.b = (A.a%m * B.b%m + A.b%m * B.d%m)%m;
    R.c = (A.c%m * B.a%m + A.d%m * B.c%m)%m;
    R.d = (A.c%m * B.b%m + A.d%m * B.d%m)%m;
    return R;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Matrix k;
    Matrix t;
    
    int n;
    
    while(cin >> n){
        if(n == -1)
            break;
        n--;
        
        k.a = 1;
        k.b = 1;
        k.c = 1;
        k.d = 0;
        
        t.a = 1;
        t.b = 0;
        t.c = 0;
        t.d = 1;
        
        while(n > 0){
            if(n&1){
                t = mult(t, k);
            }
            n /= 2;
            k = mult(k, k);
        }
        cout << t.a << endl;
    }
    
    return 0;
}
