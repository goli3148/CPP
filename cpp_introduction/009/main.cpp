#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    unsigned seed = time(NULL);
    srand(seed);

    int max, min, num;
    cout << "Enter max and min of random numbers: " << endl << "MAX: ";
    cin >> max;
    cout <<"MIN: ";
    cin >> min;
    if (min >= max) return 0;

    for (int i=0; i<10; i++){
        num = rand();
        num = num / 100%(max - min + 1) + min;
        cout << num << endl;
    }

    return 0;
}