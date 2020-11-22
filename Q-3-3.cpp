#include <bits/stdc++.h>
using namespace std;

int main(){

    char c[110];
    deque<int> num;
    deque<int> op;

    cin >> c;

    for(int i = 0,len = strlen(c) ; i < len ; i++){
        if(i&1){ //is operation
            if(c[i] == '+'){
                op.push_back(1);
            }else if(c[i] == '-'){
                op.push_back(0);
            }else if(c[i] == '*'){
                int t = num.back();
                num.pop_back();
                num.push_back(t*(c[i+1]-'0'));
                i++;
            }else if(c[i] == '/'){
                int t = num.back();
                num.pop_back();
                num.push_back(t/(c[i+1]-'0'));
                i++;
            }
        }else{ //is number
            num.push_back(c[i]-'0');
        }
    }

    for(int i = 0,len = op.size() ; i < len ; i++){
        if(op.front()){
            int v = num.front();
            num.pop_front();
            int u = num.front();
            num.pop_front();
            num.push_front(v+u);
            op.pop_front();
        }else{
            int v = num.front();
            num.pop_front();
            int u = num.front();
            num.pop_front();
            num.push_front(v-u);
            op.pop_front();
        }
    }
    cout << num.front() << endl;

    return 0;
}
