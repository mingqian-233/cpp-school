#include <iostream>
#include <string>

#include "Matrix.h"

void message(const std::string &str) {
    std::cout << str << std::endl;
}

int main() {
    Matrix A, B, C;
    double scalar;
    message("这是一个测试程序，用于测试矩阵类的各种运算。");
    message("请输入第一个矩阵 \n格式：a b c d，会形成一个矩阵\na b\nc d\n");
    std::cin >> A;

    message("请输入第二个矩阵 \n格式：a b c d\n");
    std::cin >> B;

    message("请输入一个标量值：");
    std::cin >> scalar;

    message("您输入的矩阵 A 是：");
    std::cout << A;

    message("您输入的矩阵 B 是：");
    std::cout << B;

    message("矩阵 A + B 的结果是：");
    C = A + B;
    std::cout << C;

    message("矩阵 A - B 的结果是：");
    C = A - B;
    std::cout << C;

    message("矩阵 A * B 的结果是：");
    C = A * B;
    std::cout << C;

    message("矩阵 A * 标量 的结果是：");
    C = A * scalar;
    std::cout << C;

    message("标量 * 矩阵 B 的结果是：");
    C = scalar * B;
    std::cout << C;

    message("比较矩阵 A 和 B 是否相等：");
    if (A == B) {
        message("矩阵 A 和 B 相等。");
    } else {
        message("矩阵 A 和 B 不相等。");
    }
    system("pause");
    return 0;
}