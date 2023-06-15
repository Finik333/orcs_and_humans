#include <iostream>

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
#if defined(_MSC_VER)
    wcerr.imbue(locale(".866"));
    wcout.imbue(locale(".866"));
    wcin.imbue(locale(".866"));
#else
    wcerr.imbue(locale("ru_RU.UTF-8"));
    wcout.imbue(locale("ru_RU.UTF-8"));
    wcin.imbue(locale("ru_RU.UTF-8"));
#endif

    int vr;
    wcout << L"-----[ ОРКИ И ЛЮДИ ]-----" << endl;
    You human(35, 150);

    Orc mag(35, 75);
    Orc strongman(25, 100);
    Orc baby(10, 35);

    wcout << L"Ваша сила: " << human.power << endl;
    wcout << L"Ваше здоровье: " << human.hp << endl;
    srand(time(NULL));
    int resoult = 1 + rand() % 3;
    wcout << L"Вы вышли из дома в поисках приключий, и на вашем пути попался";
    switch (resoult) {
    case 1:
        wcout << L" страшный враг маг орк" << endl;
        wcout << L"Сила мага: " << mag.power << endl;
        wcout << L"Здоровье мага: " << mag.hp << endl;
        for (int i3 = 0; i3 < 3; i3++) {
            wcout << L"Вам нужно решить что делать:1-АТАКА        2-БЕЖАТЬ" << endl;
            wcout << L"Ваш выбор:";
            wcin >> vr;
            if (vr == 1) {
                wcout << L"Вы атакавали магу и сняли ему 35 единиц здоровья" << endl;
                mag.hp = mag.hp - human.power;
                wcout << L"Здоровье мага: " << mag.hp << endl;
                if (vr == 1) {
                    srand(time(NULL));
                    int v = 1 + rand() % 3;
                    switch (v) {
                    case 1:
                        wcout << L"Враг вас успешно атаковкал" << endl;
                        human.hp = human.hp - mag.power;
                        wcout << L"Здоровье:" << human.hp;
                    case 2:
                        wcout << L"Враг успешно сбежал" << endl;
                    case 3:
                        wcout << L"Враг рискнул сбежать и за это он получил по морде" << endl;
                        mag.hp = mag.hp - human.power;
                        wcout << L"Здоровье мага: " << mag.hp << endl;
                    }
                }
            }
            else {
                srand(time(NULL));
                int p = 1 + rand() % 2;
                if (p == 1) {
                    wcout << L"Вам удалось сбежать";
                }
                else {
                    wcout << L"Вам не удалось сбежать и вас атаковал враг" << endl;
                    human.hp = human.hp - mag.power;
                    wcout << L"Здоровье:" << human.hp;
                }
            }
            break;
        }
    case 2:
        wcout << L" страшный враг громила орк" << endl;
        wcout << L"Сила громилы: " << strongman.power << endl;
        wcout << L"Здоровье громилы: " << strongman.hp << endl;
        for (int i2 = 0; i2 < 3; i2++) {
            wcout << L"Вам нужно решить что делать:1-АТАКА        2-БЕЖАТЬ" << endl;
            wcout << L"Ваш выбор:";
            wcin >> vr;
            if (vr == 1) {
                wcout << L"Вы атакавали громилу и сняли ему 35 единиц здоровья" << endl;
                strongman.hp = strongman.hp - human.power;
                wcout << L"Здоровье : " << strongman.hp << endl;
                if (vr == 1) {
                    srand(time(NULL));
                    int v = 1 + rand() % 3;
                    switch (v) {
                    case 1:
                        wcout << L"Враг вас успешно атаковкал" << endl;
                        human.hp = human.hp - strongman.power;
                        wcout << L"Здоровье:" << human.hp;
                    case 2:
                        wcout << L"Враг успешно сбежал" << endl;
                    case 3:
                        wcout << L"Враг рискнул сбежать и за это он получил по морде" << endl;
                        strongman.hp = strongman.hp - human.power;
                        wcout << L"Здоровье громилы: " << strongman.hp << endl;
                    }
                }
            }
            else {
                srand(time(NULL));
                int p = 1 + rand() % 2;
                if (p == 1) {
                    wcout << L"Вам удалось сбежать";
                }
                else {
                    wcout << L"Вам не удалось сбежать и вас атаковал враг" << endl;
                    human.hp = human.hp - strongman.power;
                    wcout << L"Здоровье:" << human.hp;
                }
            }
            break;
        }
    case 3:
        wcout << L" страшный враг мелкий орк" << endl;
        wcout << L"Сила мелкого орка: " << baby.power << endl;
        wcout << L"Здоровье мелкого орка: " << baby.hp << endl;
        for (int i3 = 0; i3 < 3; i3++) {
            wcout << L"Вам нужно решить что делать:1-АТАКА        2-БЕЖАТЬ" << endl;
            wcout << L"Ваш выбор:";
            wcin >> vr;
            if (vr == 1) {
                wcout << L"Вы атакавали мелкого и сняли ему 35 единиц здоровья" << endl;
                baby.hp = baby.hp - human.power;
                wcout << L"Здоровье мелкого: " << baby.hp << endl;
                if (vr == 1) {
                    srand(time(NULL));
                    int v = 1 + rand() % 3;
                    switch (v) {
                    case 1:
                        wcout << L"Враг вас успешно атаковкал" << endl;
                        human.hp = human.hp - baby.power;
                        wcout << L"Здоровье:" << human.hp;
                    case 2:
                        wcout << L"Враг успешно сбежал" << endl;
                    case 3:
                        wcout << L"Враг рискнул сбежать и за это он получил по морде" << endl;
                        baby.hp = baby.hp - human.power;
                        wcout << L"Здоровье мелкого: " << baby.hp << endl;
                    }

                }
            }
            else {
                srand(time(NULL));
                int p = 1 + rand() % 2;
                if (p == 1) {
                    wcout << L"Вам удалось сбежать";
                }
                else {
                    wcout << L"Вам не удалось сбежать и вас атаковал враг" << endl;
                    human.hp = human.hp - baby.power;
                    wcout << L"Здоровье:" << human.hp;
                }
            }
            break;
        }
    }

    return 0;
}
