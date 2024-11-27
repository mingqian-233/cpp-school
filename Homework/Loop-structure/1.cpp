#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x;
    cin >> y;
    int i = 1;
    int power = 1;
    power *= x;
    i++;
    if (x <= y)
        cout << power;
    return 0;
}