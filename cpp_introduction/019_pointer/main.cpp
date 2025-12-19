#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void init_pointer();
void deep_copy();
void shallow_copy();
void pointer_variable();
void pointer_to_pointer();
void pointer_refrece();
// Refrence Return Functions: ==========
void refrence_return();
int& max(int&, int&);
// Refrence Return Functions: ==========
void array_pointer();
void new_operator();
void delete_operator();
void dynamic_array();
// Pointer To Function: ==========
void pointer_funcion();
int sum(int (*pf)(int ), int);
int square(int);
int cube(int);
// Pointer To Function: ==========


int main(){
    pointer_funcion();
    dynamic_array();
    delete_operator();
    new_operator();
    array_pointer();
    refrence_return();
    pointer_refrece();
    pointer_to_pointer();
    pointer_variable();
    shallow_copy();
    deep_copy();
    init_pointer();
    return 0;
}

// Pointer To Function: ==========
void pointer_funcion(){
    cout << endl << "SUM OVER CUBE AND SQUARE" << endl;
    cout << "SQUARE: " << sum(square, 5) << endl;
    cout << "CUBE: " << sum(cube, 5) << endl;
}
int sum(int (*pf)(int k), int n){
    int s = 0;
    for (int i=1; i<=n; i++)
        s += (*pf)(i);
    return s;
}
int square(int val){return pow(val, 2);}
int cube(int val){return pow(val, 3);}
// Pointer To Function: ==========

void dynamic_array(){
    cout << endl << "DYNAMIC ARRAY" << endl;
    int* arr = new int[20];
    for (int *p = arr; p < arr + 20; p++){
        *p = rand();
    }
    for (int *p = arr; p < arr + 20; p++){
        cout << "\t p: " << p << " *p: " << *p << endl;
    }
    delete [] arr;
}

void delete_operator(){
    float* p1 = new float(3.14);
    delete p1;
    // Error 1:
    // const int* p2 = new int;
    // delete p2;
    // Error 2:
    // float x = 3.14;
    // float* p3 = &x;
    // delete p3;
}

void new_operator(){
    float* p1 = new float;
    *p1 = 3.14;
    // or
    float *p2 = new float(3.14);
}

void array_pointer(){
    typedef int var;
    cout << endl << "ARRAY POINTER" << endl;
    const int SIZE = 3;
    var a[SIZE] = {33, 22, 90};
    cout << "a: " << a << endl;
    cout << "sizeof(var): " << sizeof(var) << endl;
    var sum = 0;
    var* end = a + SIZE; 
    for (var* p=a; p < end; p++){
        sum += *p;
        cout << "\t p = " << p;
        cout << "\t *p = " << *p;
        cout << "\t sum = " << sum << endl;
    }
    cout << "[] and * operators on array: " << endl;
    for (short i=0; i<SIZE; i++){
        cout << "\t a[" << i << "]: " << a[i];
        cout << "\t *(a+" << i << "): " << *(a+i);
        cout << "\t a[" << i << "] == *(a+" << i << "): " << (a[i] == *(a+i)) << endl;
    }
}

// Refrence Return Functions: ==========
void refrence_return(){
    cout << endl << "REFRENCE RETURN" << endl;
    int a = 44;
    int b = 55;
    cout << "a: " << a << " b: " << b << " max(a, b): " << max(a, b) << endl;
    max(a, b) = 100;
    cout << "a: " << a << " b: " << b << " max(a, b): " << max(a, b) << endl;
}
int& max(int& a, int& b){
    return (a > b ? a : b);
}
// Refrence Return Functions: ==========


void pointer_refrece(){
    cout << endl << "POINTER VS REFRENCE" << endl;
    int p = 44;
    int* ptn = &p;
    cout << "p: " << p << " *p: DOES NOT EXISTS " << " &p: " << &p << endl;
    cout << "ptn: " << ptn << " *ptn: " << *ptn << " &ptn: " << &ptn << endl;
    cout << "&*p: " << *&p << " *&ptn: " << *&ptn << " &*ptn: " << &*ptn << endl;
}

void pointer_to_pointer(){
    cout << endl << "POINTER TO POINTER " << endl;
    int p = 44;
    int* ptn = &p;
    int** pptn = &ptn;
    cout << "p: " << p << " address to p: " << ptn << endl;
    cout << "ptn: " << ptn << " ptn value: " << *ptn << " address to ptn: " << pptn << endl;
    cout << "pptn: " << pptn << " pptn value: " << *pptn << " adress to pptn: " << &pptn << endl;
}

void pointer_variable(){
    cout << endl << "POINTER VARIABLE" << endl;
    int a = 44;
    int* pointer = &a;
    cout << "a: " << a << " | pointer: " << pointer << " | pointer address: " << &pointer << " | pointer value: " << *pointer << endl;
}

void deep_copy(){
    cout << endl << "DEEP COPY: " << endl;
    int a = 23;
    int copy_a = a;
    cout << "a: " << a << " deep copy of a: " << copy_a << endl;
    a ++;
    cout << "a: " << a << " deep copy of a: " << copy_a << endl;
}

void shallow_copy(){
    // Reference Oprator
    cout << endl << "SHALLOW COPY: " << endl;
    int a = 23;
    // Define Reference Operator
    int& copy_a = a;
    cout << "a: " << a << " shallow copy of a: " << copy_a << endl;
    a ++;
    cout << "a: " << a << " shallow copy of a: " << copy_a << endl;

}

void init_pointer(){
    cout << endl << "DEFINE POINTER: " << endl;
    int n = 23;
    cout << &n << endl;
}