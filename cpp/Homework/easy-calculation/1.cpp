#include <iostream>
using namespace std;

int main() {
    double celsius, fahrenheit;

    cout << "Enter a Celsius temperature: ";
    cin >> celsius;

    fahrenheit = 9.0 / 5 * celsius + 32;
    cout << "Fahrenheit equivalent: " << fahrenheit << '\n';

    return 0;
}