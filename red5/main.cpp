#include <iostream>

using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {10, 20, 30, 40, 50};
    int sum = 0;

    for (int i = 0; i < SIZE; i++) { // i выходит за массив. Считает i=5 а не должен. меняем <= на <
        sum += numbers[i];
    }

    double average = static_cast<double>(sum) / SIZE;
    cout << "Average: " << average << endl;

    return 0;
 }
