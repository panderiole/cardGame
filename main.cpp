
#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;
struct Card {
    int lear = 0;
    int value = 0;
};

array<Card, 36> generatePack() {
    array<Card, 36> pack;
    int index = 0;
    for (int i = 6; i <= 14; i++) {
        pack[index].value = i;
        pack[index].lear = 1;
        pack[index + 1].value = i;
        pack[index + 1].lear = 2;
        pack[index + 2].value = i;
        pack[index + 2].lear = 3;
        pack[index + 3].value = i;
        pack[index + 3].lear = 4;
        index += 4;
    }
    return pack;
}

array<Card, 36> mixPack(array<Card, 36> pack) {
    for (int i = 0; i < 36; i++) {
        int randomIndex = rand() % 36;
        Card timeCard = pack[i];
        pack[i] = pack[randomIndex];
        pack[randomIndex] = timeCard;
    }
    return pack;
}


string getColor(int lear) {
    string russianLear;
    if (lear == 1) {
        russianLear = "крести";
    } else if (lear == 2) {
        russianLear = "буби";
    } else if (lear == 3) {
        russianLear = "черви";
    }else if (lear == 4) {
        russianLear = "пики";
    } else {
        russianLear = "error";
    }
    return russianLear;
}

string getValue(int value) {
    string russianValue;
    if (value < 11) {
        russianValue = to_string(value);
    } else if (value == 11) {
        russianValue = "валет";
    } else if (value == 12) {
        russianValue = "дама";
    } else if (value == 13) {
        russianValue = "король";
    } else if (value == 14) {
        russianValue = "туз";
    } else {
        russianValue = "error";
    }
    return russianValue;
}

void printPack(array<Card, 36> pack) {
    for (int i = 0; i < 36; i++) {
        string russianLear = getColor(pack[i].lear);
        string russianValue = getValue(pack[i].value);
        cout << "№ " << i + 1 << " - " << russianLear << ":" << russianValue << endl;
    }
}

void findTwoNearestByColor(array<Card, 36> pack) {
    int minRange = 10000;
    int firstIndex = 0;
    int secondIndex = 0;
    for (int i = 0; i < 35; i++) {
        for (int j = i + 1; j < 36; j++) {
            if (pack[i].lear == pack[j].lear) {
                if (j - i < minRange) {
                    minRange = j - i;
                    firstIndex = i;
                    secondIndex = j;
                }
                break;
            }
        }
    }
    cout << getValue(pack[firstIndex].value) << " " << getColor(pack[firstIndex].lear) << " (" << firstIndex + 1 << " позиция)" << " и " << getValue(pack[secondIndex].value) << " " << getColor(pack[secondIndex].lear) << " (" << secondIndex + 1 << " позиция) являются самыми ближайшими в колоде при сортировке по цвету (расстояние " << minRange << ")" << endl;
}

void findTwoNearestByValue(array<Card, 36> pack) {
    int minRange = 10000;
    int firstIndex = 0;
    int secondIndex = 0;
    for (int i = 0; i < 35; i++) {
        for (int j = i + 1; j < 36; j++) {
            if (pack[i].value == pack[j].value) {
                if (j - i < minRange) {
                    minRange = j - i;
                    firstIndex = i;
                    secondIndex = j;
                }
                break;
            }
        }
    }
    cout << getValue(pack[firstIndex].value) << " " << getColor(pack[firstIndex].lear) << " (" << firstIndex + 1 << " позиция)" << " и " << getValue(pack[secondIndex].value) << " " << getColor(pack[secondIndex].lear) << " (" << secondIndex + 1 << " позиция) являются самыми ближайшими в колоде при сортировке по значению (расстояние " << minRange << ")" << endl;
}

void findQueenOfSpades(array<Card, 36> pack) {
    for (int i = 0; i < 36; i++) {
        if (pack[i].value == 12 && pack[i].lear == 4) {
            cout << "Дама пик была найдена на " << i + 1 << " позиции в колоде!" << endl;
            break;
        }
    }
}
void findAces(array<Card, 36> pack) {
    for (int i = 0; i < 36; i++) {
        if (pack[i].value == 14) {
            cout << "Туз " << getColor(pack[i].lear) << " был найден на " << i + 1 << " позиции в колоде!" << endl;
        }
    }
}

int main()
{
    array<Card, 36> pack;
    string command;
    while (true) {
        cout << "-----------------------------------------------------------\nЗдравствуйте, доступные команды:\n1 - заполнить колоду картами\n2 - перемешать колоду\n3 - найти в колоде две ближайшие карты одного цвета\n4 - найти в колоде 2 ближайшие карты одного номинала\n5 - найти даму пик\n6 - найти все тузы\n7 - напечатать все карты колоды\n8 - завершить программу\nВведите номер нужной команды: ";
        cin >> command;
        cout << endl << "-----------------------------------------------------------" << endl;
        if (command != "1" && command != "8" && pack[0].value == 0) {
            cout << "Для начала заполните колоду!" << endl;
            continue;
        }
        if (command == "1") {
            pack = generatePack();
            cout << "Колода заполнена!" << endl;
        } else if (command == "2") {
            pack = mixPack(pack);
            cout << "Колода перемешана!" << endl;
        } else if (command == "3") {
            findTwoNearestByColor(pack);
        } else if (command == "4") {
            findTwoNearestByValue(pack);
        } else if (command == "5") {
            findQueenOfSpades(pack);
        } else if (command == "6") {
            findAces(pack);
        } else if (command == "7") {
            printPack(pack);
        } else if (command == "8") {
            cout << "Хорошего дня!" << endl;
            exit(0);
        } else {
            cout << "Комманда не распознана!\n";
        }
    }
 return 0;
}
