#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_temp();

int main(){
    enum Day {SUN, MON, TUE, WED, THU, FRI, SAT};
    float temprature[SAT+1] = {};

    unsigned seed = time(NULL);
    srand(seed);
    // Fill the day with temprature
    for (int day = SUN; day <= SAT; day++){
        temprature[day] = random_temp();
    }

    // print the day temprature
    for (int day = SUN; day <= SAT; day++){
        cout << "temprature day: " << day << " is " << temprature[day] << endl;
    }
    return 0;
}

int random_temp(){
    int max = 50;
    int min = 0;
    return rand() / 100%(max - min + 1) + min;
}