#include <iostream>
#include<windows.h>
#include <stdio.h>
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
int main() {
    setlocale(0, "rus");
    system("mode con cols=160 lines=45");
    for (int i=0; i < 65; i++) {
        cout << " ";
    }
    cout << "ОРКИ И ЛЮДИ" << endl;
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
            cout << "Ваша сила: " << human.power << endl;
    cout << "Ваше здоровье: " << human.hp << endl;
    srand(time(NULL));
    int resoult = 1 + rand() % 3;
    cout << "Вы вышли из дома в поисках приключий, и на вашем пути попался";
    switch (resoult) {
    case 1: cout << " страшный враг маг орк" << endl;
        cout << "Сила мага: " << mag.power << endl;
        cout << "Здоровье мага: " << mag.hp;
    case 2: cout << " страшный враг громила орк" << endl;
        cout << "Сила громилы: " << strongman.power << endl;
        cout << "Здоровье громилы: " << strongman.hp;
    case 3: cout << " страшный враг мелкий орк" << endl;
        cout << "Сила мелкого орка: " << baby.power << endl;
        cout << "Здоровье мелкого орка: " << baby.hp;
    }
    return 0;
}
