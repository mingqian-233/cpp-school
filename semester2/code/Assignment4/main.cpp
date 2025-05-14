#include <cstdlib>
#include <ctime>
#include <iostream>

#include "zoo.h"


int main() {
    // 设置随机数种子
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "=== Zoo Simulation Starting ===" << std::endl;

    // 创建动物园实例
    Zoo zoo;

    // 运行模拟
    zoo.runSimulation();

    std::cout << "=== Zoo Simulation Ended ===" << std::endl;

    system("pause");

    
    return 0;
}
