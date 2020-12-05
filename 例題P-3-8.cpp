#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, ans;
    int a[200030];
    cin >> n >> l;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    deque<int> M;
    deque<int> m;
    M.push_front(a[0]);
    m.push_front(a[0]);

    for(int i = 1 ; i < l ; i++){
        while(!M.empty() && a[i] > M.front())
            M.pop_front();
        M.push_front(a[i]);

        while(!m.empty() && a[i] < m.front())
            m.pop_front();
        m.push_front(a[i]);
    }
    ans = M.back() - m.back();

    int s = 0, t = l;

    while(t < n){
        while(!M.empty() && a[t] > M.front())
            M.pop_front();
        M.push_front(a[t]);
        if(M.back() == a[s])
            M.pop_back();

        while(!m.empty() && a[t] < m.front())
            m.pop_front();
        m.push_front(a[t]);
        if(m.back() == a[s])
            m.pop_back();

        if(M.back()- m.back() > ans)
            ans = M.back()- m.back();

        s++;
        t++;
    }

    cout << ans << endl;

    return 0;
}
