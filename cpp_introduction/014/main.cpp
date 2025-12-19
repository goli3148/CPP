#include <iostream>

using namespace std;

//intialize array
void random_memory_initialized_array();
void zero_initialized_array();
void index_out_of_range();

int main(){
    random_memory_initialized_array();
    zero_initialized_array();
    index_out_of_range();
    return 0;
}

void random_memory_initialized_array(){
    cout << "random memory intialized ";
    int arr[9];
    for (int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void zero_initialized_array(){
    cout << "Zero intialized: ";
    int arr[9] = {};
    for (int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void index_out_of_range(){
    cout << "Index out of array: ";
    int arr[3] = {1, 2, 3};
    for (int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
