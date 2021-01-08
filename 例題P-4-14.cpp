#include <bits/stdc++.h>
using namespace std;
int n, m, p[100010], maxi = 0, sum = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    pair<int, int> a[100010];
    stack<int> ay;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
        cin >> a[i].first;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i].second;

    sort(a, a+n);

    ay.push(a[0].second);
    for(int i = 1 ; i < n ; i++){
        while(!ay.empty() && ay.top() <= a[i].second)
            ay.pop();
        ay.push(a[i].second);
    }

    cout << ay.size() << endl;

    return 0;
}
