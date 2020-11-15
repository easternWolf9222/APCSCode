#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>

#define m 1000000009

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
    
    long long x, y, n;
    cin >> x >> y >> n;
    
    n--;
        
    k.a = x;
    k.b = 2*y;
    k.c = y;
    k.d = x;
        
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
    cout << ((x*t.a)%m + (y*t.b)%m)%m << " " << ((x*t.c)%m + (y*t.d)%m)%m << endl;
    
    return 0;
}
