#include <bits/stdc++.h>
using namespace std;
struct sword{
    int t, w;
};

//compare t/v
bool compare(sword a, sword b){
    return a.t * b.w > b.t * a.w;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long sum = 0;
    sword a[100010];
    long long prefixWeight[100010];

    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].w;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].t;
    sort(a, a+n, compare);

    prefixWeight[0] = 0;
    for(int i = 1 ; i < n ; i++)
        prefixWeight[i] = prefixWeight[i-1]+a[i-1].w;
    for(int i = 0 ; i < n ; i++)
        sum += prefixWeight[i] * a[i].t;

    cout << sum << endl;

    return 0;
}
