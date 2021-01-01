//玄之又玄

#include <iostream>

using namespace std;

int main(){
    int n, index, tmp, maxi = 0;
    int record[200010];
    for(int i = 0 ; i < 200010 ; i++)
        record[i] = 599999999;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        index = lower_bound(record, record+i+1, tmp) - record;
        record[index] = min(tmp, record[index]);
        if(index+1 > maxi)
            maxi = index+1;
    }

  cout << maxi << endl;
}
