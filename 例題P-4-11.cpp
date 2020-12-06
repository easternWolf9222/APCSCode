#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    pair<int, int> a[200020];

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n);

    int endOfS = a[0].second;
    int lengthOfS = a[0].second - a[0].first;

    for(int i = 1 ; i < n ; i++){
        if(a[i].first > endOfS){
            endOfS = a[i].second;
            lengthOfS += a[i].second - a[i].first;
        }else if(a[i].second > endOfS){
            lengthOfS += a[i].second - endOfS;
            endOfS = a[i].second;
        }
    }

    cout << lengthOfS << endl;

    return 0;
}
