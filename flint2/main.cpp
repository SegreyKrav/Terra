#include <iostream>
#include <clocale>
#include "odin.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    sayHello(); // работает Один

    int a, b;
    readTwo(a, b);  // работает tor

    cout << a << " + " << b << " = " << add(a, b) << endl;

    return 0;
}
