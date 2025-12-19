#include <iostream>
using namespace std;

class Widget{
    public:
        Widget(){counter++;}
        ~Widget(){counter--;}
        static int counter;
};       
void show(int);

int Widget::counter = 0;

int main(){
    Widget w, x;
    show(w.counter);
    {
        Widget w, x, y, z;
        show(w.counter);
    }
    show(w.counter);
    Widget y;
    show(w.counter);
    return 0;
}

void show(int counter){
    cout << "Number of counters: " << counter << endl;
}