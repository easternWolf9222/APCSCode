#include <bits/stdc++.h>
using namespace std;

int main() {

    char c[160];
    stack<int> s;
    bool stat = true;

    while(cin >> c){
        int len = strlen(c);
        stat = true;

        for(int i = 0 ; i < len ; i++){
            if(c[i] == '(')
                s.push(1);
            else if(c[i] == '[')
                s.push(2);
            else if(c[i] == '{')
                s.push(3);
            else if(c[i] == ')'){
                if(s.empty() || s.top() != 1){
                    stat = false;
                    break;
                }
                s.pop();

            }else if(c[i] == ']'){
                if(s.empty() || s.top() != 2){
                    stat = false;
                    break;
                }
                s.pop();
            }else if(c[i] == '}'){
                if(s.empty() || s.top() != 3){
                    stat = false;
                    break;
                }
                s.pop();
            }
        }

        if(!s.empty())
            stat = false;

        if(stat)
            cout << "yes\n";
        else
            cout << "no\n";

        while(!s.empty())
            s.pop();
    }
    return 0;
}
