#include <bits/stdc++.h>
using namespace std;

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

    void changeName(string name) {
        this->name = name;
    }
};

int Spirit::number = 0;
int Spirit::alivenumber = 0;

int main() {
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

    // task 2
    s1.takeDamage(999);
    s1.getInfo();
    s1.takeDamage(1);
    s1.getInfo();
    
    // task 3
    cout << "Position of s1: (" << s1.getPositionX() << ", " << s1.getPositionY() << ")" << endl;
    cout << "Name of s1: " << s1.getName() << endl;
    cout << "Health of s1: " << s1.getHealth() << endl;
    cout << "Alive number: " << s1.getAliveNumber() << endl;
    cout << endl;



    return 0;
}