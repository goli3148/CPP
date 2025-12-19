#include <iostream>

using namespace std;
typedef float Sequence[];
void print(Sequence, int);
void bubble_sort(Sequence, int);

int main(){
    Sequence a = {22, -10, 0, 43, 10, -1};

    bubble_sort(a, 6);

    for (int i=0; i<6; i++){
        print(a, i);
    }
    return 0;
}

void bubble_sort(Sequence a, int n){
    for (int i=n-1; i>0; i--){
        for (int j=0; j<i; j++){
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void print(Sequence a, int index){
    cout << a[index] << endl;
}