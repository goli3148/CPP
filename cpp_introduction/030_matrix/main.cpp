#include <iostream>
using namespace std;


class Matrix{
    public:
        Matrix(double a, double b, double c, double d);
        Matrix(){};
        
        friend Matrix operator+(const Matrix&, const Matrix&);
        friend Matrix operator-(const Matrix&, const Matrix&);
        friend Matrix operator*(const Matrix&, const Matrix&);
        friend Matrix operator*(const Matrix&, double);
        friend Matrix operator*(double, const Matrix&);

        Matrix inverse();
        double det();
        bool singular();
        void print();
    
    private:
        double m[2][2];
};

Matrix::Matrix(double a, double b, double c, double d): m{{a, b}, {c, d}} {
}

Matrix operator+(const Matrix& a, const Matrix& b){
    Matrix res;
    
    for(int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            res.m[i][j] = a.m[i][j] + b.m[i][j];

    return res;
}

Matrix operator-(const Matrix& a, const Matrix& b){
    Matrix res;
    
    for(int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            res.m[i][j] = a.m[i][j] - b.m[i][j];

    return res;
}

Matrix operator*(const Matrix& a, const Matrix& b){
    Matrix res;
    
    res.m[0][0] = a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0];
    res.m[0][1] = a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1];
    res.m[1][0] = a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0];
    res.m[1][1] = a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1];

    return res;
}

Matrix operator*(const Matrix& a, double scalar) {
    Matrix res;
    res.m[0][0] = a.m[0][0] * scalar;
    res.m[0][1] = a.m[0][1] * scalar;
    res.m[1][0] = a.m[1][0] * scalar;
    res.m[1][1] = a.m[1][1] * scalar;
    return res;
}

Matrix operator*(double scalar, const Matrix& a) {
    return a * scalar; // Uses the operator above
}

Matrix Matrix::inverse(){
    if (singular())
        return *this;

    double d = det();

    Matrix res;
    
    res.m[0][0] = m[1][1] / d;
    res.m[0][1] = -m[0][1] / d;
    res.m[1][0] = -m[1][0] / d;
    res.m[1][1] = m[0][0] / d;
    
    return res;
}

double Matrix::det(){
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

bool Matrix::singular(){
    return det()==0;
}

void Matrix::print() {
    cout << "[" << m[0][0] << ", " << m[0][1] << "]" << endl;
    cout << "[" << m[1][0] << ", " << m[1][1] << "]" << endl;
}

int main() {
    cout << "=== Testing Matrix Class ===" << endl << endl;
    
    // Test 1: Create matrices
    cout << "1. Creating matrices:" << endl;
    Matrix A(1, 2, 3, 4);
    Matrix B(5, 6, 7, 8);
    
    cout << "Matrix A:" << endl;
    A.print();
    cout << endl;
    
    cout << "Matrix B:" << endl;
    B.print();
    cout << endl;
    
    // Test 2: Determinant
    cout << "2. Determinants:" << endl;
    cout << "det(A) = " << A.det() << endl;
    cout << "det(B) = " << B.det() << endl;
    cout << endl;
    
    // Test 3: Singularity check
    cout << "3. Singularity check:" << endl;
    cout << "A is singular? " << (A.singular() ? "Yes" : "No") << endl;
    cout << "B is singular? " << (B.singular() ? "Yes" : "No") << endl;
    
    // Create a singular matrix
    Matrix C(1, 2, 2, 4);
    cout << "Matrix C (singular):" << endl;
    C.print();
    cout << "det(C) = " << C.det() << endl;
    cout << "C is singular? " << (C.singular() ? "Yes" : "No") << endl;
    cout << endl;
    
    // Test 4: Addition
    cout << "4. Matrix addition:" << endl;
    cout << "A + B:" << endl;
    (A + B).print();
    cout << endl;
    
    // Test 5: Subtraction
    cout << "5. Matrix subtraction:" << endl;
    cout << "A - B:" << endl;
    (A - B).print();
    cout << endl;
    
    // Test 6: Matrix multiplication
    cout << "6. Matrix multiplication:" << endl;
    cout << "A * B:" << endl;
    (A * B).print();
    cout << endl;
    
    // Test 7: Scalar multiplication
    cout << "7. Scalar multiplication:" << endl;
    cout << "A * 2.5:" << endl;
    (A * 2.5).print();
    cout << endl;
    
    cout << "3.0 * B:" << endl;
    (3.0 * B).print();
    cout << endl;
    
    // Test 8: Inverse
    cout << "8. Matrix inverse:" << endl;
    cout << "Inverse of A:" << endl;
    Matrix A_inv = A.inverse();
    A_inv.print();
    cout << endl;
    
    // Verify A * A_inv = Identity (approximately)
    cout << "Verifying A * A_inv (should be near identity):" << endl;
    (A * A_inv).print();
    cout << endl;
    
    // Test 9: Inverse of singular matrix
    cout << "9. Inverse of singular matrix C:" << endl;
    Matrix C_inv = C.inverse();
    C_inv.print();
    cout << endl;
    
    // Test 10: Combined operations
    cout << "10. Combined operations:" << endl;
    cout << "2*A + B - A:" << endl;
    (2.0*A + B - A).print();
    cout << endl;
    
    cout << "(A + B) * 0.5:" << endl;
    ((A + B) * 0.5).print();
    cout << endl;
    
    // Test 11: Identity matrix operations
    cout << "11. Testing with identity matrix:" << endl;
    Matrix I(1, 0, 0, 1);
    cout << "Identity matrix I:" << endl;
    I.print();
    cout << endl;
    
    cout << "A * I (should equal A):" << endl;
    (A * I).print();
    cout << endl;
    
    cout << "I * A (should equal A):" << endl;
    (I * A).print();
    cout << endl;
    
    cout << "=== All tests completed ===" << endl;
    
    return 0;
}