#include <bits/stdc++.h>
/*
 在图中的九个点上,空出中间的点,其余的点上任意填入数字1到8;1的位置固定不动,然后移动其余的数字,使1到8顺时针从小到大排列.移动的规律是:只能将数字沿线移向空白的点。请编程显示数字移动过程。
 */
using namespace std;

void transfrom(const auto &a, auto &b) {
    b[0][0] = a[0];
    b[0][1] = a[1];
    b[0][2] = a[2];
    b[1][2] = a[3];
    b[2][2] = a[4];
    b[2][1] = a[5];
    b[2][0] = a[6];
    b[1][0] = a[7];
}
void print(const auto &v) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[i][j] == 0)
                cout << "0";
            else
                cout << v[i][j];
            if (j != 2) {
                cout << "-";
            }
        }
        cout << '\n';
        if (i != 2)
            cout << "|\\|/|" << '\n';
    }
    cout << '\n';
}
void change(const auto &a, int t, int place_of_1) {
    // 第一个参数为一维序列，第二个为要被交换到中间的数字
    int swap_ind = 0;  // 在a中索引要被交换的数字的位置
    for (int i = 0; i < 8; i++) {
        if (a[i] == t) {
            swap_ind = i;
            break;
        }
    }
}

int generate(auto &a) {  // 返回假定顺时针，左上角为1开始，1在第几个位置
    int one_place = 0;
    a[1][1] = 0;
    vector<int> v;
    for (int i = 1; i <= 8; i++) v.push_back(i);
    mt19937 g(random_device{}());
    shuffle(v.begin(), v.end(), g);
    for (int i = 0; i < 8; i++) {
        if (v[i] == 1) return i;
    }
}
void play() {
    vector<int> a(8);
    int place_of_1 = generate(a);
    for (int move_num = 2; move_num <= 8; move_num++) {
        int ind = (place_of_1 + move_num - 1) % 8;  // 当前枚举到的数字原本应该处于的下标
        if (a[ind] != move_num) change(a, move_num, place_of_1);
    }
}

int main() {
    play();
    return 0;
}
