#include <iostream>
using namespace std;

class x{
    public:
        int data;
};

int main(){
    x* p = new x;
    (*p).data = 22;
    cout << "(*p).data: " << (*p).data << " p->data: " << p->data << endl;
    p->data = 44;
    cout << "(*p).data: " << (*p).data << " p->data: " << p->data << endl;
    return 0;
}