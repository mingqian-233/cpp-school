#include <bits/stdc++.h>
using namespace std;
int main() {
    int counter = 0;
    int number;
    int max_num = INT_MIN;

    while (counter < 10) {
        cout << "Enter a number: ";
        cin >> number;
        max_num = max(max_num, number);
        counter++;
    }

    cout << "The largest number is: " << max_num << '\n';
    return 0;
}