#include <iostream>

#include "Library.h"

using namespace std;

int main() {
    
    cout<<"读入图书馆的初始状态。选择你希望的输入方式。\n";
    cout<<"1. 从文件读取数据。文件名：books.txt\n";
    cout<<"2. 从键盘输入数据\n";
    cout<<"3. 退出程序\n";
    int choice;
    cin>>choice;
    if(choice==3){
        cout<<"程序结束。";
        return 0;
    }
    Library library;
    library.inputInitialState(choice);
    cout<<"图书馆的初始状态读入完成。\n";

    cout<<"读入借书人信息。选择你希望的输入方式。\n";
    cout<<"1. 从文件读取数据。文件名：borrowers.txt\n";
    cout<<"2. 从键盘输入数据\n";
    cout<<"3. 退出程序\n";
    cin>>choice;
    if(choice==3){
        cout<<"程序结束。";
        return 0;
    }
    library.inputBorrowerInfo(choice);
    cout<<"借书人信息读入完成。\n";

    system("pause");
    return 0;
}
