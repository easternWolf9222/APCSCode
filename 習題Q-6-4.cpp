//imgur.com/gallery/tYZ96LI

#include <bits/stdc++.h>
using namespace std;

int abso(int a){
    if(a < 0)
        return -a;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, a, b;
    cin >> n >> l;
    int a1, b1, a2, b2, ca1, cb1, ca2, cb2;

    cin >> a1 >> b1;
    ca1 = abso(a1-l);
    cb1 = abso(b1-l);

    for(int i = 1 ; i < n ; i++){
        cin >> a2 >> b2;
        ca2 = min(abso(a2-a1)+ca1, abso(a2-b1)+cb1);
        cb2 = min(abso(b2-a1)+ca1, abso(b2-b1)+cb1);
        a1 = a2;
        b1 = b2;
        ca1 = ca2;
        cb1 = cb2;
    }
    cout << min(ca2, cb2) << endl;
    return 0;
}
