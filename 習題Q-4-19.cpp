#include <bits/stdc++.h>
using namespace std;

struct event{
    int people;
    bool stat; // start(1) or end(0)
    int time;
};

bool cmp(event a, event b){
    return (a.time < b.time) || (a.time == b.time && a.stat > b.stat);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t1, t2, t3;
    event a[200020];

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> t1 >> t2 >> t3;
        a[i*2].people = t1;
        a[i*2].stat = 1;
        a[i*2].time = t2;

        a[i*2+1].people = t1;
        a[i*2+1].stat = 0;
        a[i*2+1].time = t3;
    }

    sort(a, a+2*n, cmp);

    int now = a[0].people;
    int maxi = now;

    int k = 1;
    for(int i = 1 ; i < 2*n ; i++){
        if(a[i].stat){
            now += a[i].people;
            maxi = max(maxi, now);
        }else{
            now -= a[i].people;
        }
    }

    cout << maxi << endl;

    return 0;
}
