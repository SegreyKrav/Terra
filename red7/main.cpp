#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

struct Student {
    string fio;
    string birthDate;
    int height;
    int weight;
    double bmi;
};

// Функция для удаления лишних пробелов
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (string::npos == first) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Ошибка: Не удалось открыть файл students.txt!" << endl;
        return 1;
    }

    Student students[100];
    int count = 0;
    string line;

    getline(file, line); // Пропускаем заголовок
    regex datePattern("[0-9]{4}-[0-9]{2}-[0-9]{2}");

    // Чтение и парсинг
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string fio, birthDate, heightStr, weightStr;

        getline(ss, fio, ';');       fio = trim(fio);
        getline(ss, birthDate, ';'); birthDate = trim(birthDate);
        getline(ss, heightStr, ';'); heightStr = trim(heightStr);
        getline(ss, weightStr, ';'); weightStr = trim(weightStr);

        if (regex_search(birthDate, datePattern)) {
            students[count].fio = fio;
            students[count].birthDate = birthDate;
            students[count].height = stoi(heightStr);
            students[count].weight = stoi(weightStr);

            double h = students[count].height / 100.0;
            students[count].bmi = students[count].weight / (h * h);

            count++;
        }
    }
    file.close();

    // ============ ВЫВОД ИСХОДНОГО СПИСКА ============
    cout << "=== Исходный список студентов ===" << endl;
    cout << left << setw(35) << "ФИО"
         << setw(15) << "Дата рождения"
         << setw(10) << "Рост(см)"
         << setw(10) << "Вес(кг)"
         << "ИМТ" << endl;
    cout << string(80, '-') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(35) << students[i].fio
             << setw(15) << students[i].birthDate
             << setw(10) << students[i].height
             << setw(10) << students[i].weight
             << fixed << setprecision(2) << students[i].bmi << endl;
    }
    cout << endl << endl;


    // ============ ЗАДАНИЕ 1 ============
    cout << "=== 1. Самая молодая студентка-девушка ===" << endl;
    int youngest = -1;
    for (int i = 0; i < count; ++i) {
        string surname = students[i].fio.substr(0, students[i].fio.find(' '));
        bool isFemale = (surname.back() == 'а' || surname.back() == 'я');

        if (isFemale) {
            if (youngest == -1 || students[i].birthDate > students[youngest].birthDate) {
                youngest = i;
            }
        }
    }
    if (youngest != -1) {
        cout << students[youngest].fio << " (" << students[youngest].birthDate << ")" << endl;
    }
    cout << endl;


    // ============ ЗАДАНИЕ 2 ============
    cout << "=== 2. Только ФИО и Вес ===" << endl;
    cout << left << setw(35) << "ФИО" << setw(10) << "Вес(кг)" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < count; ++i) {
        cout << left << setw(35) << students[i].fio
             << setw(10) << students[i].weight << endl;
    }
    cout << endl;


    // ============ ЗАДАНИЕ 3 ============
    cout << "=== 3. Максимальный ИМТ ===" << endl;
    int maxBmiIdx = 0;
    for (int i = 1; i < count; ++i) {
        if (students[i].bmi > students[maxBmiIdx].bmi) {
            maxBmiIdx = i;
        }
    }

    cout << "Студент: " << students[maxBmiIdx].fio << endl;
    cout << "Рост:    " << students[maxBmiIdx].height << " см" << endl;
    cout << "Вес:     " << students[maxBmiIdx].weight << " кг" << endl;
    cout << fixed << setprecision(2);
    cout << "ИМТ:     " << students[maxBmiIdx].bmi << endl;

    return 0;
}
