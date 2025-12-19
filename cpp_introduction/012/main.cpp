#include <iostream>
#include <cmath>
using namespace std;

void ComputeCircle(double&, double&, const double&);

int main(){
    double r, a, c;
    cout << "Enter circle radius: ";
    cin >> r;
    ComputeCircle(a, c, r);
    cout << "Area: " << a << ", circumference: " << c << endl;
    return 0;
}

// const pointer: 1. reduce memory 2. only readable
void ComputeCircle(double& area, double& circumference, const double& r){
    area = M_PI * pow(r, 2);
    circumference = 2 * M_PI * r;
}