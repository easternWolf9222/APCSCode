#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

// GFEDCBA
// 1111111
// 10000000 - 1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    int sum = (1 << m) - 1;
    string input[50100];
    int newForm[50100] = {0};
    int cnt = 0;
    
    for(int i = 0 ; i < n ; i++){
        cin >> input[i];
        int len = input[i].length();
        for(int j = 0 ; j < len ; j++)
            newForm[i] = newForm[i] | 1<<(input[i][j] - 'A');
    }
    
    sort(newForm, newForm+n);
    
    for(int i = 0 ; i < n ; i++){
        if(binary_search(newForm, newForm+n, sum-newForm[i])){
            cnt++;
        }
    }
    cout << cnt/2 << endl;
    
    
    return 0;
}
