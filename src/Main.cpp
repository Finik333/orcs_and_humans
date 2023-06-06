#include <iostream>
using namespace std;
class you {
public:
    int power;
    int hp;
};
class orcs {
public:
    int power;
    int hp;
};
void print_line() {
    int i,int i1,int i2,int i3,int i4;
    for (i = 0; i < 100; i++) {
        cout << "#";
    } for (i4 = 0; i4 < 25; i4++) {
        cout << "#" << endl;
        for (i1 = 0; i1 < 1; i1++) {
            cout << "#";
        }
        for (i3 = 0; i3 < 99; i3++) {
            cout << " ";
        }
    }
}
int main() {
    setlocale(0, "rus");
    cout << "ОРКИ И ЛЮДИ" << endl;
    print_line();
    you human;
    human.power = 35;
    human.hp = 150;

    orcs mag;
    mag.power = 35;
    mag.hp = 75;
    orcs strongman;
    strongman.power = 25;
    strongman.hp = 100;
    orcs baby;
    baby.power = 10;
    baby.hp = 35;
    srand(time(NULL));
    int resoult = 1 + rand() % 3;
    cout << resoult;
        return 0;
}
