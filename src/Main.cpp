#include <iostream>
#include <stdio.h>

using namespace std;

class You {
public:
    You(int power, int hp) : power(power), hp(hp) {
    }

    int power;
    int hp;
};

class Orc {
public:
    Orc(int power, int hp) : power(power), hp(hp) {
    }

    int power;
    int hp;
};

int main() {
    setlocale(0, "rus");
    system("mode con cols=160 lines=45");
    int vr;
    for (int i = 0; i < 65; i++) {
        cout << " ";
    }
    cout << "ОРКИ И ЛЮДИ" << endl;
    You human(35, 150);

    Orc mag(35, 75);
    Orc strongman(25, 100);
    Orc baby(10, 35);

    cout << "Ваша сила: " << human.power << endl;
    cout << "Ваше здоровье: " << human.hp << endl;
    srand(time(NULL));
    int resoult = 1 + rand() % 3;
    cout << "Вы вышли из дома в поисках приключий, и на вашем пути попался";
    switch (resoult) {
    case 1:
        cout << " страшный враг маг орк" << endl;
        cout << "Сила мага: " << mag.power << endl;
        cout << "Здоровье мага: " << mag.hp << endl;
        for (int i3 = 0; i3 < 3; i3++) {
            cout << "Вам нужно решить что делать:1-АТАКА        2-БЕЖАТЬ" << endl;
            cout << "Ваш выбор:";
            cin >> vr;
            if (vr == 1) {
                cout << "Вы атакавали магу и сняли ему 35 единиц здоровья" << endl;
                mag.hp = mag.hp - human.power;
                cout << "Здоровье мага: " << mag.hp << endl;
                if (vr == 1) {
                    srand(time(NULL));
                    int v = 1 + rand() % 3;
                    switch (v) {
                    case 1:
                        cout << "Враг вас успешно атаковкал" << endl;
                        human.hp = human.hp - mag.power;
                        cout << "Здаровье:" << human.hp;
                    case 2:
                        cout << "Враг успешно сбежал" << endl;
                    case 3:
                        cout << "Враг рискнул сбежать и за это он получил по морде" << endl;
                        mag.hp = mag.hp - human.power;
                        cout << "Здоровье мага: " << mag.hp << endl;
                    }
                }
            }
            else {
                srand(time(NULL));
                int p = 1 + rand() % 2;
                if (p == 1) {
                    cout << "Вам удалось сбежать";
                }
                else {
                    cout << "Вам не удалось сбежать и вас атаковал враг" << endl;
                    human.hp = human.hp - mag.power;
                    cout << "Здаровье:" << human.hp;
                }
            }
            break;
        }
    case 2:
        cout << " страшный враг громила орк" << endl;
        cout << "Сила громилы: " << strongman.power << endl;
        cout << "Здоровье громилы: " << strongman.hp << endl;
        for (int i2 = 0; i2 < 3; i2++) {
            cout << "Вам нужно решить что делать:1-АТАКА        2-БЕЖАТЬ" << endl;
            cout << "Ваш выбор:";
            cin >> vr;
            if (vr == 1) {
                cout << "Вы атакавали громилу и сняли ему 35 единиц здоровья" << endl;
                strongman.hp = strongman.hp - human.power;
                cout << "Здоровье : " << strongman.hp << endl;
                if (vr == 1) {
                    srand(time(NULL));
                    int v = 1 + rand() % 3;
                    switch (v) {
                    case 1:
                        cout << "Враг вас успешно атаковкал" << endl;
                        human.hp = human.hp - strongman.power;
                        cout << "Здаровье:" << human.hp;
                    case 2:
                        cout << "Враг успешно сбежал" << endl;
                    case 3:
                        cout << "Враг рискнул сбежать и за это он получил по морде" << endl;
                        strongman.hp = strongman.hp - human.power;
                        cout << "Здоровье громилы: " << strongman.hp << endl;
                    }
                }
            }
            else {
                srand(time(NULL));
                int p = 1 + rand() % 2;
                if (p == 1) {
                    cout << "Вам удалось сбежать";
                }
                else {
                    cout << "Вам не удалось сбежать и вас атаковал враг" << endl;
                    human.hp = human.hp - strongman.power;
                    cout << "Здаровье:" << human.hp;
                }
            }
            break;
        }
    case 3:
        cout << " страшный враг мелкий орк" << endl;
        cout << "Сила мелкого орка: " << baby.power << endl;
        cout << "Здоровье мелкого орка: " << baby.hp << endl;
        for (int i3 = 0; i3 < 3; i3++) {
            cout << "Вам нужно решить что делать:1-АТАКА        2-БЕЖАТЬ" << endl;
            cout << "Ваш выбор:";
            cin >> vr;
            if (vr == 1) {
                cout << "Вы атакавали мелкого и сняли ему 35 единиц здоровья" << endl;
                baby.hp = baby.hp - human.power;
                cout << "Здоровье мелкого: " << baby.hp << endl;
                if (vr == 1) {
                    srand(time(NULL));
                    int v = 1 + rand() % 3;
                    switch (v) {
                    case 1:
                        cout << "Враг вас успешно атаковкал" << endl;
                        human.hp = human.hp - baby.power;
                        cout << "Здаровье:" << human.hp;
                    case 2:
                        cout << "Враг успешно сбежал" << endl;
                    case 3:
                        cout << "Враг рискнул сбежать и за это он получил по морде" << endl;
                        baby.hp = baby.hp - human.power;
                        cout << "Здоровье мелкого: " << baby.hp << endl;
                    }

                }
            }
            else {
                srand(time(NULL));
                int p = 1 + rand() % 2;
                if (p == 1) {
                    cout << "Вам удалось сбежать";
                }
                else {
                    cout << "Вам не удалось сбежать и вас атаковал враг" << endl;
                    human.hp = human.hp - baby.power;
                    cout << "Здаровье:" << human.hp;
                }
            }
            break;
        }
    }

    return 0;
}
