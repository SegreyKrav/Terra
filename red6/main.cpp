#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


int countChar(const string& str, char target) {
    int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    cout << "===== Задание 1 =====" << endl;
    string fullName;
    cout << "Введите ФИО (например, Иванов Иван Иванович): ";
    getline(cin, fullName);

    cout << "Длина строки: " << fullName.length() << " символов" << endl;

    size_t firstSpace = fullName.find(' ');
    if (firstSpace == string::npos) {
        cout << "Ошибка: нет пробелов!" << endl;
        return 1;
    }
    cout << "Позиция первого пробела: " << firstSpace << endl;

    string surname = fullName.substr(0, firstSpace);
    string rest = fullName.substr(firstSpace + 1);
    cout << "Фамилия: " << surname << endl;

    size_t secondSpace = fullName.find(' ', firstSpace + 1);
    string name, patronymic;

    if (secondSpace != string::npos) {
        name = fullName.substr(firstSpace + 1, secondSpace - firstSpace - 1);
        patronymic = fullName.substr(secondSpace + 1);
        cout << "Имя:     " << name << endl;
        cout << "Отчество:" << patronymic << endl;
    } else {
        name = rest;
        cout << "Имя:     " << name << endl;
    }

    string shortName;
    if (secondSpace != string::npos) {
        shortName = surname + "_" + name[0] + "." + patronymic[0] + ".";
    } else {
        shortName = surname + "_" + name[0] + ".";
    }
    cout << "\nСокращенное ФИО: " << shortName << endl;


    cout << "\n===== Задание 2 =====" << endl;
    char target;
    cout << "Введите символ для подсчёта в вашем ФИО: ";
    cin >> target;

    int count = countChar(fullName, target);
    cout << "Символ '" << target << "' встречается " << count << " раз(а)." << endl;

    return 0;
}
