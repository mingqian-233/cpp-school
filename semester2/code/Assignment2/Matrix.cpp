#include "Matrix.h"

#include <iostream>

Matrix::Matrix() {
    data[0][0] = 1;
    data[0][1] = 0;
    data[1][0] = 0;
    data[1][1] = 1;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            os << m.data[i][j] << " ";
        }
        os << '\n';
    }
    return os;
}
std::istream &operator>>(std::istream &is, Matrix &m) {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            is >> m.data[i][j];
        }
    }
    if (std::cin.fail()) {
        std::cerr << "呃，你输入的是啥啊？\n";
        system("pause");
        exit(1);
    }
    return is;
}

Matrix Matrix::operator+(const Matrix &m) const {
    Matrix res;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            res.data[i][j] = data[i][j] + m.data[i][j];
        }
    }
    return res;
};
Matrix Matrix::operator-(const Matrix &m) const {
    Matrix res;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            res.data[i][j] = data[i][j] - m.data[i][j];
        }
    }
    return res;
};
Matrix Matrix::operator*(const Matrix &m) const {
    Matrix res;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            res.data[i][j] = 0;
            for (int k = 0; k <= 1; k++) {
                res.data[i][j] += data[i][k] * m.data[k][j];
            }
        }
    }
    return res;
};
Matrix Matrix::operator*(double d) const {
    Matrix res;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            res.data[i][j] = data[i][j] * d;
        }
    }
    return res;
};
Matrix operator*(double d, const Matrix &m) {
    return m * d;
};

Matrix &Matrix::operator*=(const Matrix &m) {
    *this = *this * m;
    return *this;
};
Matrix &Matrix::operator*=(double d) {
    *this = *this * d;
    return *this;
};
Matrix &Matrix::operator+=(const Matrix &m) {
    *this = *this + m;
    return *this;
};
Matrix &Matrix::operator-=(const Matrix &m) {
    *this = *this - m;
    return *this;
};
bool Matrix::operator==(const Matrix &m) const {
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            if (abs(data[i][j] - m.data[i][j]) > 1e-9) {
                return false;
            }
        }
    }
    return true;
};
bool Matrix::operator!=(const Matrix &m) const {
    return !(*this == m);
};

Matrix::~Matrix() {
#ifdef DEBUG
    std::cout << "Matrix destroyed" << std::endl;
#endif
}