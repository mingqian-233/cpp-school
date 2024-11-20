#include <bits/stdc++.h>
using namespace std;

// use mt19937 to generate random number
int get_rand_num(int lower, int upper) {
    mt19937 rd(random_device{}());
    uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}

class Spirit {
private:
    string name;
    int x;
    int y;
    int health = 1000;
    bool aliveState = true;

public:
    static int number;
    static int alivenumber;

    Spirit() {
        number++;
        alivenumber++;
    }
    Spirit(string name, int x, int y) {
        this->name = name;
        this->x = x;
        this->y = y;
        number++;
        alivenumber++;
    }

    void takeDamage(int damage) {
        if (aliveState) {
            cout << "Spirit " << name << " has been attacked and lost " << damage << " health." << endl;
            health -= damage;
            if (health <= 0) {
                health = 0;
                aliveState = false;
                alivenumber--;
                cout << "Spirit is dead." << endl;
            }
        } else {
            cout << "Spirit has been dead." << endl;
        }
    }

    void setPosition(int x, int y) {
        auto in_0_to_200 = [&](auto r) {
            for (auto i : r) {
                if (!(i >= 0 && i <= 200)) return false;
            }
            return true;
        };
        if (in_0_to_200(vector<int>{x, y})) {
            this->x = x;
            this->y = y;
        }
    }
    void changeName(string name) {
        this->name = name;
    }

    int getPositionX() {
        return x;
    }
    int getPositionY() {
        return y;
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getAliveNumber() {
        return alivenumber;
    }
    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Position: (" << x << ", " << y << ")" << endl;
        cout << "Alive: " << (aliveState ? "Yes" : "No") << endl;
        cout << endl;
    }
};

int Spirit::number = 0;
int Spirit::alivenumber = 0;

int main() {
    cout << "Hello! Please choose the mode:\n";
    cout << "1. Test Mode:\n";
    cout << "2. Extra Mode:\n";
    cout << "3. Exit\n";
    int mode;
    cin >> mode;
    if (mode == 3) {
        return 0;
    }
    if (mode == 1) {
        // task 1
        string name1;
        cout << "Please enter the name of the first spirit: \n";
        cin >> name1;
        cout << "Please enter the position of the first spirit, separated by a space: \n";
        int x1, y1;
        cin >> x1 >> y1;
        Spirit s1(name1, x1, y1);
        s1.getInfo();

        Spirit s2 = Spirit();
        string name2;
        cout << "Please enter the name of the second spirit: \n";
        cin >> name2;
        cout << "Please enter the position of the second spirit, separated by a space: \n";
        int x2, y2;
        cin >> x2 >> y2;
        s2.changeName(name2);
        s2.setPosition(x2, y2);
        s2.getInfo();

        system("pause");
        system("cls");

        // task 2
        cout << "Assume that s1 is attacked by 999 damage and 1 damage." << endl;
        s1.takeDamage(999);
        s1.getInfo();
        s1.takeDamage(1);
        s1.getInfo();
        system("pause");
        system("cls");

        // task 3
        cout << "Test all the functions." << endl;
        cout << "Position of s1: (" << s1.getPositionX() << ", " << s1.getPositionY() << ")" << endl;
        cout << "Name of s1: " << s1.getName() << endl;
        cout << "Health of s1: " << s1.getHealth() << endl;
        cout << "Alive number: " << s1.getAliveNumber() << endl;
        cout << endl;
        system("pause");
        system("cls");

        // task 4
        cout << "Randomly generate 10 spirits." << endl;
        Spirit spirits[10];
        for (int i = 0; i < 10; i++) {
            int x = get_rand_num(0, 200);
            int y = get_rand_num(0, 200);
            string name = "Spirit" + to_string(i);
            spirits[i] = Spirit(name, x, y);
            spirits[i].getInfo();
        }
        system("pause");
        system("cls");

        // task 5
        cout << "Randomly attack 10 spirits and attack them." << endl;
        for (int i = 0; i < 10; i++) {
            int object = get_rand_num(0, 9);
            int damage = get_rand_num(0, 1000);
            spirits[object].takeDamage(damage);
        }
        s1.getInfo();
        s2.getInfo();
        for (int i = 0; i < 10; i++) spirits[i].getInfo();

        cout << "Task finished." << '\n';

        system("pause");
        system("cls");

        cout << Spirit::number << ' ' << Spirit::alivenumber << '\n';  // 22 20
        Spirit::number = 0;
        Spirit::alivenumber = 0;
        cout << Spirit::number << ' ' << Spirit::alivenumber << '\n';  // 0 0

        system("pause");
        system("cls");

        main();
    }

    if (mode == 2) {
        // for (int i = 1; i <= 200; i++) cout << '*';
        // the screen is big enough.
        cout << "Please choose the mode: \n";
        cout << "1. PvP Mode. \n";
        cout << "2. PvE Mode. \n";
        int mode;
        cin >> mode;

        vector<Spirit> spirits;
    }

    return 0;
}