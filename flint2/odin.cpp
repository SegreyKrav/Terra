#include "odin.h"
#include <iostream>
using namespace std;

void sayHello() {
    cout << "Привет, я Один!" << endl;
}

int add(int a, int b) {
    return a + b;
}

void readTwo(int& a, int& b) {
    cout << "Введи первое число: ";
    cin >> a;
    cout << "Введи второе число: ";
    cin >> b;
}
