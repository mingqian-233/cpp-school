#include <bits/stdc++.h>
using namespace std;
bool multiple(int a, int b) {
    return !(b % a);
}
int main() {
    int a, b;
    while (cin >> a >> b) {
        bool is_multiple = multiple(a, b);
        if (is_multiple) {
            cout << b << " is a multiple of " << a << endl;
        } else {
            cout << b << " is not a multiple of " << a << endl;
        }
    }
    return 0;
}