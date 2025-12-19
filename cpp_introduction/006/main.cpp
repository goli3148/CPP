#include <iostream>
using namespace std;

int main(){
    int number, counter, sum;
    float mean = 0;
    sum = 0;
    counter = 0;
    for (; ;){
        cout << "Enter a number (0 for quire): ";
        cin >> number;
        if (number == 0) break;
        counter += 1;
        sum += number;
    }
    mean = (counter!=0 ? float(sum) / counter : 0);
    cout << "mean is: " << mean << endl;

    return 0;
}