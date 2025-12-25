#include <iostream>
#include <cstddef>


// Template function for addition
template <typename T>
T add(T a, T b){
    return a + b;
}

// implicit and explicit template instantiation
template <typename T>
void f(T a){}
void g(){
    f(3); // implicit instantiation
    f<short>(3.5); // explicit instantiation
}

// variadic template
template <typename... Args>
auto print(Args... args) {
    ((std::cout << "Arg: " << args << std::endl), ...);
}

// std::size_t
template <std::size_t... Indices>
void printIndices() {
    ((std::cout << Indices << " "), ...) << std::endl;
}


int main(){
    // first test
    std::cout << add(3, 4) << std::endl;       // Integer addition
    std::cout << add(3.5, 4.2) << std::endl;   // Floating-point addition
    print(1, 2, 3, 4, 5);
    print("Hello", "World", 42);
    printIndices<1, 2, 3, 4, 5>();
    return 0;
}