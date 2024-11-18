#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x;
    cin >> y;
    int i = 1;
    int power = 1;
    while (1) {
        power *= x;
        i++;
        if (i <= y)
            continue;
        else {
            cout << power;
            break;
        }
    }
    return 0;
}