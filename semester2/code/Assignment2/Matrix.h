
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
class Matrix {
private:
    double data[2][2];

public:
    Matrix();
    ~Matrix();
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    // 必须是非成员函数（通常声明为 friend），因为左操作数是流对象
    friend std::istream &operator>>(std::istream &, Matrix &);  // 这个地方const的话就输入不了了

    Matrix operator+(const Matrix &) const;
    // const分别保证不改变右操作数的值和左操作数的值。左操作数是*this，右操作数是传入的参数，&节省内存开销。
    // 注意这里不可以写成Matrix&。因为在函数内部要定义res之后返回，等于返回一个被释放的局部引用
    Matrix operator-(const Matrix &) const;
    Matrix operator*(const Matrix &) const;
    Matrix operator*(double) const;
    // 左操作和右操作是double的情况要分别实现
    friend Matrix operator*(double, const Matrix &);

    Matrix &operator*=(const Matrix &);
    // 这里需要修改*this，不能加const
    Matrix &operator*=(double);
    Matrix &operator+=(const Matrix &);
    Matrix &operator-=(const Matrix &);

    bool operator==(const Matrix &) const;
    bool operator!=(const Matrix &) const;
};
#endif
