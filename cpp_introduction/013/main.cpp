#include <iostream>
#include <cmath>
using namespace std;

void ComputeCircle(double&, double&, double=5);

int main(){
    double r, a, c;
    cout << "Enter circle radius(0 use default value): ";
    cin >> r;
    if (r==0) ComputeCircle(a, c);
    else ComputeCircle(a, c, r);
    cout << "Area: " << a << ", circumference: " << c << endl;
    
    return 0;
}

// const pointer: 1. reduce memory 2. only readable
void ComputeCircle(double& area, double& circumference, double r){
    area = M_PI * pow(r, 2);
    circumference = 2 * M_PI * r;
}