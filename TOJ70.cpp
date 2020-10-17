#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double r1, i1, r2, i2; //一定要double!!!! 卡超久!!!
    char d;
    cin >> r1 >> i1 >> d >> r2 >> i2;
    
    if(d == '+'){
        if(i1 + i2 < 0){
            cout << fixed << setprecision(2) << r1 + r2 << i1 + i2 << "i\n";
        }else{
            cout << fixed << setprecision(2) << r1 + r2 << "+" << i1 + i2 << "i\n";
        }
    }
    
    if(d == '-'){
        if(i1 - i2 < 0){
            cout << fixed << setprecision(2) << r1 - r2 << i1 - i2 << "i\n";
        }else{
            cout << fixed << setprecision(2) << r1 - r2 << "+" << i1 - i2 << "i\n";
        }
    }
    
    if(d == '*'){
        if(r1*i2 + r2*i1 < 0){
            cout << fixed << setprecision(2) << r1*r2 - i1*i2 << r1*i2 + r2*i1 << "i\n";
        }else{
            cout << fixed << setprecision(2) << r1*r2 - i1*i2 << "+" << r1*i2 + r2*i1 << "i\n";
        }
    }
    
    if(d == '/'){
        if((-r1*i2+r2*i1)/(r2*r2+i2*i2) < 0){
            cout << fixed << setprecision(2) << (r1*r2+i1*i2)/(r2*r2+i2*i2) << (-r1*i2+r2*i1)/(r2*r2+i2*i2) << "i\n";
        }else{
            cout << fixed << setprecision(2) << (r1*r2+i1*i2)/(r2*r2+i2*i2) << "+" << (-r1*i2+r2*i1)/(r2*r2+i2*i2) << "i\n";
        }
    }
    
    
    return 0;
}
