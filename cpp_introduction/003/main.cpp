#include <cmath>
#include <iostream>

// Rounding Error

using namespace std;

int main(){
    float a, b, c;
    cout << "input the ax**2 + bx + c = 0 numbers: (a,b,c)" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    float d = b*b - 4*a*c;
    float sqrtd = sqrt(d);
    if (d < 0){
        cout << "no answere: " << sqrtd << endl;
    }
    else if(d == 0){
        float x = - b / (2*a);
        float check = a * x * x + b * x + c;
        cout << "only one answere: " << x << endl;
        cout << "check answere: " << check << endl;
        
    }
    else if(sqrtd > 0){
        float x1 = ((-b + sqrtd)/(2*a));
        float x2 = ((-b - sqrtd)/(2*a));
        float check1 = a * x1 * x1 + b * x1 + c;
        float check2 = a * x2 * x2 + b * x2 + c;
        cout << "two answeres found -> x1: " << x1 << " x2: " << x2 << endl;
        cout << "two check -> x1: " << check1 << " x2: " << check2 << endl;
    }
    return 0;
}