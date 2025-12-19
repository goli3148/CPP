#include <iostream>
using namespace std;

int LinearSearch(int, int[], int);
void BubbleSort(int[], int);
int BinarySearch(int, int[], int);

int main(){
    // Linear Search
    const int SIZE = 5;
    int a[] = {66, 33, 44, 55, -20};
    int x = 100;
    int index = LinearSearch(x, a, SIZE);
    cout << "x: " << x << endl;
    if (index == -1) cout << "Number did not found" << endl;
    else cout << "Number index is [" << index << "]." << endl;

    //Bubble Sort
    BubbleSort(a, SIZE);
    for (int i=0; i<SIZE; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    //Binary Search Using sorted array
    index = BinarySearch(x, a, SIZE);
    cout << "x: " << x << endl;
    if (index == -1) cout << "Number did not found" << endl;
    else cout << "Number index is [" << index << "]." << endl;

    return 0;
}

int LinearSearch(int x, int numbers[], int n){
    for (int i=0; i<n; i++){
        if (numbers[i] == x) return i;
    }
    return -1;
}

void BubbleSort(int a[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

int BinarySearch(int x, int a[], int n){
    for (int i=n/2; i>-1; ){
        if (a[i] == x) return i;
        else if (a[i] > x) i = i / 2;
        else if (a[i] < x) i = 3 * i / 2;
        if (i==0 || i >= n) break;
    }
    return -1;
}