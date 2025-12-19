#include <iostream>
using namespace std;

// INFERENCE
class Ratio{
    public:
    // Constructors
    Ratio(); // Default Constructor
    // Ratio(int); // Default Contructor
    Ratio(int numerator=0, int denumerator=1);
    ~Ratio();
    void print();
    double convert();
    void invert();
    private:
    int num, den;
};

int main(){
    Ratio x(15, 3);
    Ratio y(16, 4);
    Ratio z(20);
    x.print();
    cout << x.convert() << endl;
    y.print();
    cout << y.convert() << endl;
    z.print();
    cout << z.convert() << endl;
    
    {
        cout << "Create a Ratio class";
        Ratio ratio();
    }

    return 0;
}

// Destroyer
Ratio::~Ratio(){
    cout << "Object Dies \n";
}

// IMPLEMENTATION
// Two type of constructor in two same way
// 1.
// Ratio::Ratio(): num(1), den(1) { }
// 2.
// Ratio::Ratio(){
//     num = 1;
//     den = 1;
// }

// Two type of constructor in two same way
// 1.
// Ratio::Ratio(int numerator): num(numerator), den(1) { }
// 2.
// Ratio::Ratio(int numerator){
//     num = numerator;
//     den = 1;
// }

// Three type of constructor in two same way
// 1.
// Ratio::Ratio(int numerator, int denumerator): num(numerator), den(denumerator) { }
// 2.
// Ratio::Ratio(int numerator, int denumerator){
//     num = numerator;
//     den = denumerator;
// }
// 3.
Ratio::Ratio(int numerator, int denumerator) : num(numerator), den(denumerator) { }

double Ratio::convert(){
    return double(num)/den;
}

void Ratio::invert(){
    int temp = num;
    num = den;
    den = temp;
}

void Ratio::print(){
    cout << num << "/" << den << ": ";
}