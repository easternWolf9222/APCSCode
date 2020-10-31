#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

string a;
int n;
int p;

int count(int length){
    if(a[p] == '2'){
        p++;
        return count(length/2) + count(length/2) + count(length/2)+ count(length/2);
    }else if(a[p] == '1'){
        p++;
        return pow(length,2);
    }else{
        p++;
        return 0;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> n;
    p = 0;
    cout << count(n) << endl;
    
    return 0;
}
