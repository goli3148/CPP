#include <iostream>
using namespace std;

typedef int gen;

class Vector{
    public:
        Vector(int len);
        friend Vector operator+(const Vector& a, const Vector& b);
        friend Vector operator*(const Vector& a, const Vector& b);
        void fill(gen* vector);
        void show_all();
    private:
        int len;
        gen* vector;
};

Vector operator+(const Vector& a, const Vector& b){
    if (a.len != b.len){
        throw runtime_error("Vectors must have same length for addition!");
    }
    Vector result(a.len);
    for (int i=0; i<a.len; i++){
        result.vector[i] = a.vector[i] + b.vector[i];
    }
    return result;
}

Vector operator*(const Vector& a, const Vector& b){
    if (a.len != b.len){
        throw runtime_error("Vectors must have same length for addition!");
    }
    Vector result(a.len);
    for (int i=0; i<a.len; i++){
        result.vector[i] = a.vector[i] * b.vector[i];
    }
    return result;
}

int main(){
    Vector vector1(5);
    Vector vector2(5);
    gen v1[] = {1, 2, 3, 4, 5};
    gen v2[] = {6, 7, 8, 9, 10};
    
    vector1.fill(v1);
    vector2.fill(v2);

    vector1.show_all();
    vector2.show_all();

    Vector c(5);
    c = vector1 * vector2;
    c.show_all();

    return 0;
}

Vector::Vector(int len){
    this->len = len;
    vector = new gen[len];
}

void Vector::fill(gen* vector){
    this->vector = vector;
}

void Vector::show_all(){
    for (int i=0; i<len; i++){
        cout << "\t" << *(vector+i);
    }
    cout << endl;
}