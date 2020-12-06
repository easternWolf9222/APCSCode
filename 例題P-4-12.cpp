//O(n)
//磨練看出最優方式的直覺!

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp, minimum = 1000000000, profit_max = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        if(tmp < minimum)
            minimum = tmp;
        if(tmp - minimum > profit_max)
            profit_max = tmp - minimum;
    }
    cout << profit_max << endl;
    return 0;
}
