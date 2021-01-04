#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t1, root, sum = 0;
    int numOfChild[100010];
    int parent[100010] = {0};
    int height[100010] = {0};
    queue<int> leaf;
    vector<int> child[100010];

    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> numOfChild[i];
        if(numOfChild[i] == 0)
            leaf.push(i);
        for(int j = 0 ; j < numOfChild[i] ; j++){
            cin >> t1;
            parent[t1] = i;
            child[i].push_back(t1);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(parent[i] == 0){
            root = i;
            break;
        }
    }

    while(!leaf.empty()){
        t1 = leaf.front();
        leaf.pop();
        numOfChild[parent[t1]]--;
        if(t1 != root && numOfChild[parent[t1]] == 0)
            leaf.push(parent[t1]);
        for(int v : child[t1]){
            height[t1] = max(height[t1], height[v]+1);
        }
        sum += height[t1];
    }

    cout << root << endl << sum << endl;
    return 0;
}
