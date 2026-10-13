#include <iostream>
#include <clocale>
using namespace std;

void convert(int time, int* minut, int* sec) {
    *minut = time / 60;
    *sec = time % 60;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int time;
    cout << "¬ведите врем€ в секундах: ";
    cin >> time;

    int minut, sec;
    convert(time, &minut, &sec);

    cout << "Ёто " << minut << " мин " << sec << " сек" << endl;

    return 0;
}
