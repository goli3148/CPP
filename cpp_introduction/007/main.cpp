#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    // random numbers generated from one seed are like each other.
    unsigned seed;
    cout << "enter seed: ";
    cin >> seed;
    srand(seed);

    for (int i=0; i<8; i++){
        cout << rand() << endl;
    }
    cout << "RAND MAX: " << RAND_MAX << endl;
    return 0;
}