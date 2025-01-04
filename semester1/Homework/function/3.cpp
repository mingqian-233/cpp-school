#include <bits/stdc++.h>
using namespace std;

// use mt19937 to generate random number
int get_rand_num(int lower, int upper) {
    mt19937 rd(random_device{}());
    uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}
int stupid_take(int num) {
    return get_rand_num(1, min(4, num));
}
int clever_take(int take) {
    return 5 - take;
}
void game(int mode) {
    int num = 21;
    int round = 0;
    while (num) {
        round++;
        cout << "Round " << round << ":\n";
        cout << "Number of sticks left: " << num << '\n';
        int take;
        cout << "How many sticks do you want to take ? (1-" << min(4, num) << "): ";
        while (cin >> take) {
            if (take >= 1 && take <= min(4, num)) {
                break;
            } else {
                cout << "Invalid input, please enter again: ";
            }
        }
        num -= take;

        if (num == 0) {
            cout << "You lose. TWT " << endl;
            break;
        }

        int computer_take;
        if (mode == 1)
            computer_take = stupid_take(num);
        else
            computer_take = clever_take(take);
        cout << "Computer takes " << computer_take << " sticks." << endl;
        num -= computer_take;

        if (num == 0) {
            cout << "You win! ^_^" << endl;
            break;
        }
    }
}

int main() {
    int mode;
    cout << "Choose the mode:\n";
    cout << "1. Stupid Computer\n2. Smart Computer\n";
    cin >> mode;
    game(mode);
    bool new_game;
    cout << "New game? (1/0): ";
    cin >> new_game;
    if (new_game) {
        system("cls");
        main();
    } else {
        cout << "Goodbye!" << endl;
        return 0;
    }
    return 0;
}