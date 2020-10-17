//
//  main.cpp
//  Hello again
//
//  Created by Antony on 2020/10/17.
//  Copyright © 2020 Antony. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        
        if(x1 == x2 && y1 == y2){ //兩人在同一點上
            cout << 1 << endl;
            
        }else if(x1 == x2){ //x座標一樣
            cout << abs(y1-y2) + 1 << endl;
            
        }else if(y1 == y2){ //y座標一樣
            cout << abs(x1-x2) + 1 << endl;
            
        }else{
            int a = abs(x1-x2);
            int b = abs(y1-y2);
            int t;
            while(b != 0) //做輾轉相除，得最大公因數
            {
                t = b;
                b = a%b;
                a = t;
            }
            cout << abs(x1-x2) + abs(y1-y2) + a << endl;
        }
    }
    return 0;
}
