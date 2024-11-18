#include <iostream>
using namespace std;

int main() {
    double sum=0;
    string message[]= {"first", "second", "third"};
    for(int i = 0; i < 3; i++) {
        double num;
        cout << "Enter the " << message[i] << " number: ";
        cin >> num;
        sum += num;
    }
    double average = sum / 3;
    cout << "Average is: " << average << endl;
    
    return 0;
}