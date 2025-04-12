#include <iostream>

#include "Library.h"

using namespace std;

int main() {
    Library library;
    cout << "Welcome to the Library Management System!" << endl;

    library.input();

    library.display();
    system("pause");
    return 0;
}
