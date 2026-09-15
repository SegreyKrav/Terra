#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(0) );

std::string word;
std::cout<<"Введите ФИО: ";
std::getline(std::cin, word);
for (int i = 0, j = word.size() - 1; i < j; i++, j--)
{
    char temp = word[i];
    word[i]  = word[j];
    word[j]  = temp;
}
std::cout<<"Ваш пароль: " <<word<< std::endl;

return 0;
}
