#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout<<(i+j-2)%n+1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}