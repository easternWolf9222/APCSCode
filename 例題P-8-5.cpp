#include <bits/stdc++.h>
using namespace std;

struct machines{
    int l, r, cntL, cntR;
};

int n, m, box[100010], good[102], t;
machines machine[100010];

int dfs(int s){
    if(s >= n){
        return box[s-n];
    }

    machine[s].cntL = dfs(machine[s].l);
    machine[s].cntR = dfs(machine[s].r);

    return machine[s].cntL + machine[s].cntR;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0 ; i <= n-1 ; i++)
        cin >> box[i]; // actually, the number is i+n.

    for(int i = 0 ; i < m ; i++)
        cin >> good[i];

    for(int i = 0 ; i < n-1 ; i++){
        cin >> t;
        cin >> machine[t].l >> machine[t].r;
        machine[t].cntL = 0;
        machine[t].cntR = 0;
    }

    t = dfs(1);

    for(int i = 0 ; i < m ; i++){
        t = 1;
        while(t <= n-1){
            if(machine[t].cntL <= machine[t].cntR){
                machine[t].cntL += good[i];
                t = machine[t].l;
            }else{
                machine[t].cntR += good[i];
                t = machine[t].r;
            }
        }
        if(i == m-1)
            cout << t << endl;
        else
            cout << t << " ";
    }
    return 0;
}
