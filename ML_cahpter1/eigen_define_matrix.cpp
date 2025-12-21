#include <Eigen/Dense>
#include <iostream>
using namespace std;

// define matrix and vector using eigen
typedef Eigen::Matrix<float, 3, 3> MyMatrix33f;
typedef Eigen::Matrix<float, 3, 1> MyVector3f;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MyMatrix;

int main()
{
    MyMatrix33f a;
    MyVector3f v;
    MyMatrix m(10, 5);
    a = MyMatrix33f::Zero(); // fill matrix elements with Zero
    cout << "Zero matrix a:\n" << a << endl;
    a = MyMatrix33f::Identity(); // fill matrix elements with Identity
    cout << "Identity matrix a:\n" << a << endl;
    v = MyVector3f::Random(); // fill vector elements with random number
    cout << "Random vector v:\n" << v << endl;

    // fill matrix using comma initializer
    a << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;
    cout << "matrix a:\n" << a << endl;

    // direct element access for filling the variable
    a(0, 0) = 3;
    cout << "matrix a:\n" << a << endl;

    // using map to wrap array into Eigen types
    int data[] = {1, 2, 3, 4};
    Eigen::Map<Eigen::RowVectorXi> v1(data, 4);
    cout << "vector v1:\n" << v1 << endl;

    // using map to wrap vector into Eigen types
    vector<float> data2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Eigen::Map<MyMatrix33f> v2(data2.data());
    cout << "matrix v2:\n" << v2 << endl;

    

    return 0;
}