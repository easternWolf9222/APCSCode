// Example program
#include <iostream>
#include <string>
using namespace std;


int func(){
    char s[200];
    cin >> s;
    
    if(s[0] == 'f'){
        int x = func();
        return 2*x - 3;
    }else if(s[0] == 'g'){
        int x = func();
        int y = func();
        return 2*x + y - 7;
    }else if(s[0] == 'h'){
        int x = func();
        int y = func();
        int z = func();
        return 3*x - 2*y + z;
    }else{
        return atoi(s);
    }
}

int main()
{
    int ans = func();
    cout <<  ans << endl;
    
    return 0;
}

