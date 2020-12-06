#include <bits/stdc++.h>
using namespace std;
struct sword{
    int t, v;
};

//compare t/v
bool compare(sword a, sword b){
    return a.t * b.v < b.t * a.v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long sum = 0;
    sword a[100010];
    long long prefixTime[100010];

    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].t;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].v;
    sort(a, a+n, compare);

    prefixTime[0] = a[0].t;
    for(int i = 1 ; i < n ; i++)
        prefixTime[i] = prefixTime[i-1]+a[i].t;
    for(int i = 0 ; i < n ; i++)
        sum += prefixTime[i] * a[i].v;

    cout << sum << endl;

    return 0;
}
