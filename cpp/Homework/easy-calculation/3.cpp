#include <iostream>
using namespace std;
int main() {
    int number;
    cout << "Enter a five-digit number: ";
    while (cin >> number) {
        if (number >= 10000 && number <= 99999)
            break;
        else
            cout << "Invalid input. Please enter a five-digit number: ";
    }
    string messages[] = {"Ones", "Tens", "Hundreds", "Thousands", "Ten-thousands"};
    for (int i = 0; i < 5; i++) {
        int digit = number % 10;
        cout << messages[i] << " digit is: " << digit << '\n';
        number /= 10;
    }

    return 0;
}