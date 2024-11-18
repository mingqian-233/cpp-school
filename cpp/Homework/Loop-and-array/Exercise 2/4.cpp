#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt=0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string empty(n - i, ' ');
        cout << empty;
        for (int j = 1; j <= i; j++) {
            cnt++;
            cout << cnt << ' ';
        }
        cout<<'\n';
    }
    return 0;
}