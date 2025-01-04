#include <bits/stdc++.h>
using namespace std;
int main() {
    int counter = 0;
    int number;
    int max_num = INT_MIN, min_num = INT_MAX, sum = 0;

    while (counter < 10) {
        cout << "Enter a number: ";
        cin >> number;
        max_num = max(max_num, number);
        min_num = min(min_num, number);
        sum += number;
        counter++;
    }
    double average = 1.0 * (sum - min_num - max_num) / 8;
    cout << "The largest number is: " << max_num << '\n';
    cout << "The smallest number is: " << min_num << '\n';
    cout << "The average of the remain number is: " << average << '\n';
    return 0;
}