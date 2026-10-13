#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;
// мена числа через 3 переменную
void swp(int& a, int& b){

int t=a;
a=b;
b=t;
}
// сам пузырек
void bs(int* ar, int n) {
    for (int i = 0; i < n - 1; ++i) {
            bool sw= false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (ar[j] > ar[j + 1]) {
                swp(ar[j],ar[j+1]);
    sw= true;
            }
        }
        if (!sw) break; // если он уже отсортирован
    }
}
// вывод массы
 void par(int* ar, int n){
 if(n<=20){
    for( int i=0; i<n; ++i) cout<<ar[i]<<" ";
 }
 else { cout<<" Первые 10: ";

 for (int i = 0; i < 10; ++i) cout << ar[i] << " ";
        cout << endl << "Последние 10: ";
        for (int i = n - 10; i < n; ++i) cout << ar[i] << " ";
    }
    cout << endl;
 }
 // рандом числа
 void fr(int* ar, int n){
  for( int i =0; i<n; ++i) ar[i]= rand()%10000;
 }
 int main() {
    srand(time(0));
 SetConsoleOutputCP(1251);
 SetConsoleCP(1251);
    int n;
    cout << "Размер массива: ";
    cin >> n;

    int* ar = new int[n];

    int m;
    cout << "Режим: 1 - вручную, 2 - случайно: ";
    cin >> m;

    if (m == 1) {
        cout << "Введи " << n << " чисел: ";
        for (int i = 0; i < n; ++i) cin >> ar[i];
    } else {
        fr(ar, n);
        cout << "Массив заполнен случайно." << endl;
    }

    bs(ar, n);

    cout << "Отсортировано: ";
    par(ar, n);

    delete[] ar;
    return 0;
}
