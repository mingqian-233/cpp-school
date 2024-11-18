#include <iostream>
#include <vector>

using namespace std;

int main() {
    string number;
    cout << "Enter number: ";
    cin >> number;
    int n=number.size();
    for(int i = 1; i <= n; i++) {
        cout <<"["<<i<<"]: "<< number[n-i] << "\n";
    }
    

    return 0;
}