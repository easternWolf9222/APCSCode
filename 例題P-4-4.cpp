//注意sort比較函數的用法

#include <bits/stdc++.h>
using namespace std;
struct event{
    int s;
    int e;
    bool stat;
};

bool compare(event a, event b){
    return a.e < b.e;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    event a[100020];
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i].s >> a[i].e;
        a[i].stat = 1;
    }
    sort(a, a+n, compare);

    int i = 0;
    while(i < n){
        if(a[i].stat){
            cnt++;
            int j = i;
            while(a[j].s <= a[i].e){
                a[j].stat = 0;
                j++;
            }
        }
        i++;
    }

    cout << cnt << endl;

    return 0;
}
