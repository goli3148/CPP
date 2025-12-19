#include <iostream>
#include "swap.cpp"
using namespace std;


void swap_numbers(float&, float&);
int main(){
    float x, y;
    cout << "Swap numbers." << endl << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    swap_numbers(x, y);
    cout << "x: " << x << " y: " << y << endl;
    return 0;
}
