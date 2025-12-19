#include <iostream>

int main(){
    int n, max;
    std::cout << "enter a number(0 for quite): ";
    std::cin >> n;
    for (max=n; n > 0; ){
        max = (n > max ? n : max);
        std::cout <<"enter a number(0 for quite): ";
        std::cin >> n;
    }
    std::cout << "the maximum number is: " << max << std::endl;
    return 0;
}