#include <iostream>

using namespace std;
int n, cnt = 0;
int a[30];

void f(int k, int product){
    if(k == n){
        if(product == 1)
            cnt++;
            return;
    }
    f(k + 1, (product * a[k])%10009);
    f(k + 1, product%10009);
}

int main()
{

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    
    f(0, 1);
    
    cout << cnt - 1 << endl;

    return 0;
}
