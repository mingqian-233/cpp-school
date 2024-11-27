#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int i, j;
    double a;
    double b;

    cout << setprecision(2);

    for (i = 1; i <= 2; i++) {  // 初始化i
        cout << "i is now equal to " << i << endl;
        for (j = 0; j <= 3; j++) {
            cout << "\tj is now equal to " << j << endl;
            cout << "\t\ti + j = " << i + j << "\ti - j = " << i - j << endl;
            cout << "\t\ti * j = " << i * j << "\ti ^ j = " << pow(i, j) << endl;

            if (j == 0)
                continue;
            else {
                a = i;
                b = j;
                cout << "\t\ti / j = " << a / b << "\ti % j = " << fmod(a, b) << endl;
            }
        }
    }
    cout << "\nThe final values of i and j are: " << i << " and " << j << endl;
    return 0;
}