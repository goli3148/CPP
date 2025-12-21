#include <iostream>
#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>

typedef float DType;
using Matrix = Eigen::Matrix<DType, Eigen::Dynamic, Eigen::Dynamic>;

class LinearRegression{
    public:
        LinearRegression(int n) : n(n), weights(Matrix::Zero(n, 1)) {}
        void train(Matrix x, Matrix y);
        Matrix predict(Matrix x);
        Matrix add_cols(Matrix x);

    private:
        int n;
        Matrix weights;

};


void LinearRegression::train(Matrix x, Matrix y){
    Eigen::LeastSquaresConjugateGradient<Matrix> solver;
    solver.setMaxIterations(10000);
    solver.setTolerance(1e-6);
    Matrix x_ = add_cols(x);
    solver.compute(x_);
    weights = solver.solve(y);

    // print the x, y and weights shape
    std::cout << "X shape: " << x.rows() << ":" << x.cols() << std::endl;
    std::cout << "Y shape: " << y.rows() << ":" << y.cols() << std::endl;
    std::cout << "Weights shape: " << weights.rows() << ":" << weights.cols() << std::endl;
    std::cout << "Weights: " << weights.transpose() << std::endl;
    std::cout << "Training error: " << (predict(x) - y).norm() << std::endl;

}

Matrix LinearRegression::add_cols(Matrix x){
    x.conservativeResize(x.rows(), x.cols()+1);
    x.col(x.cols() - 1) = Matrix::Ones(x.rows(), 1);
    return x;
}

Matrix LinearRegression::predict(Matrix x){
    x = add_cols(x);
    return x * weights;
}

int main(){
    int n = 10;
    // example a line
    Matrix x(n, 1);
    x << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
    Matrix y(n, 1);
    y = 2 * x.array() + 5;

    LinearRegression lr(n);
    lr.train(x, y);
    std::cout << lr.predict(x).transpose() << std::endl;
    return 0;
}