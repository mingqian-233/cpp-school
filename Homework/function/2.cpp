#include <bits/stdc++.h>
using namespace std;
int sum(auto a) {
    int ret = 0;
    for (const auto &i : a) {
        ret += i;
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << sum(a) << endl;
    return 0;
}