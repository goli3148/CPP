#include <iostream>
using namespace std;

class Ratio{
    friend int numReturn(Ratio);
    public:
        Ratio(int n, int d): num(n), den(d) {};
    private:
        int num, den;
};

int numReturn(Ratio r){
    return r.num;
}

void test_friend_func(){
    Ratio x(22, 7);
    cout << numReturn(x) << endl;
}

int main(){
    
    return 0;
}