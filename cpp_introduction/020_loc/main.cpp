#include <iostream>

using namespace std;
typedef int val;
val* loc(val* a1, val* a2, short n1, short n2);

int main(){
    val a1[7] = {1, 2, 3, 4, 5, 6, 7};
    val a2[3] = {1, 2, 3};
    short n1 = 7;
    short n2 = 3;
    val* p = loc(a1, a2, n1, n2);
    if (p){
        cout << "Array a2 found at locations\t " << p << endl;
        for (int i = 0; i<3; i++){
            cout << "\t" << &p[i] << ": " << p[i] << "\t" << &a2[i] << ": " << a2[i] << endl;
        }
    }
    return 0;
}

val* loc(val* a1, val* a2, short n1, short n2){
    for(val* p1 = a1; p1 < a1 + n1; p1++){
        if (*p1 == *a2){
            int j;
            for (j=0; j<n2; j++){
                if (p1[j] != a2[j]) break;
            }
            if (j == n2) return p1;
        }
    }
    return 0;
}