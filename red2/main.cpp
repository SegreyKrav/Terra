#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(0));

    std::string word;
    std::cout << "Введите ФИО: ";
    std::getline(std::cin, word);

    int limit;
    std::cout << "Введите максимальное число символов: ";
    std::cin >> limit;

    if (limit <= 0)
    {
        std::cout << "Число должно быть положительным!" << std::endl;
        return 1;
    }


    int len = 0;
    while (word[len] != '\0')
        len++;


    if (len > limit)
        len = limit;


    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        char temp = word[i];
        word[i]   = word[j];
        word[j]   = temp;
        i++;
        j--;
    }


    std::cout << "Ваш пароль: ";
    for (int k = 0; k < len; k++)
        std::cout << word[k];
    std::cout << std::endl;

    return 0;
}
