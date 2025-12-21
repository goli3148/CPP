#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
int main(){
    Matrix2d a = Matrix2d::Random();
    Matrix2d b = Matrix2d::Random();
    Matrix2d result = a + b;
    std::cout << "Matrix A:\n" << a << "\n\nMatrix B:\n" << b << "\n\nResult (element-wise addition):\n" << result << std::endl;

    std::cout << "\nresult should be: " << std::endl;
    std::cout << a(0, 0) + b(0, 0) << " " << a(0, 1) + b(0, 1) << "\n";
    std::cout << a(1, 0) + b(1, 0) << " " << a(1, 1) + b(1, 1) << std::endl;

    result = a.array() * b.array();
    std::cout << "\nResult (element-wise multiplication):\n" << result << std::endl;
    std::cout << "\nresult should be: " << std::endl;
    std::cout << a(0, 0) * b(0, 0) << " " << a(0, 1) * b(0, 1) << "\n";
    std::cout << a(1, 0) * b(1, 0) << " " << a(1, 1) * b(1, 1) << std::endl;

    result = a * b;
    std::cout << "\nResult (matrix multiplication):\n" << result << std::endl;
    std::cout << "\nresult should be: " << std::endl;
    std::cout << a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0) << " " << a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1) << "\n";
    std::cout << a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0) << " " << a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1) << std::endl;

    Eigen::MatrixXf m(4, 4);
    m.setRandom();
    std::cout << "\nMatrix M (4x4):\n" << m << std::endl;
    std::cout << "\n block start (1,1) to (2,2):\n" << m.block(1,1,2,2) << std::endl;
    m.block(1,1,2,2) *= 4;
    std::cout << "\n block start (1,1) to (2,2) after *= 4:\n" << m.block(1,1,2,2) << std::endl;

    m.row(1).array() += 3;
    std::cout << "\nRow 1 after += 3:\n" << m.row(1) << std::endl;

    m.col(1).array() -= 2;
    std::cout << "\nColumn 1 after -= 2:\n" << m.col(1) << std::endl;

    Eigen::MatrixXf mat(2, 4);
    Eigen::VectorXf v(2);
    mat.setRandom();
    v.setRandom();
    std::cout << "\nMatrix A (2x4):\n" << mat << std::endl;
    std::cout << "\nVector B (2):\n" << v << std::endl;
    mat.colwise() += v;
    std::cout << "\nMatrix A (2x4) after colwise() += v:\n" << mat << std::endl;

    return 0;
}