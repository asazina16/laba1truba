#include <iostream>
#include "objects.hpp"
using namespace std;

void dobavittrubu(Pipe& p)
{
    cout << "Название трубы: ";
    cin >> p.name;
    cout << "Длина (км): ";
    cin >> p.length;
    while (cin.fail() || p.length <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка. Введите число больше 0: ";
        cin >> p.length;
    }
    cout << "Диаметр (мм): ";
    cin >> p.diameter;
    while (cin.fail() || p.diameter <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Ошибка. Введите число больше 0: ";
        cin >> p.diameter;
    }
    int x;
    cout << "Ремонт? (1 - да, 0 - нет): ";
    cin >> x;
    while (cin.fail() || (x != 0 && x != 1))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите 0 или 1: ";
        cin >> x;
    }
    p.repair = x;
}

void pokazattrubu(const Pipe& p)
{
    cout << "\nТруба\n";
    cout << "Название: " << p.name << "\n";
    cout << "Длина: " << p.length << " км\n";
    cout << "Диаметр: " << p.diameter << " мм\n";
    cout << "Ремонт: " << (p.repair ? "Да" : "Нет") << "\n";
}

void redaktirovatrubu(Pipe& p)
{
    int x;
    cout << "\n1 - Отправить в ремонт\n";
    cout << "2 - Убрать из ремонта\n";
    cout << "0 - Назад\n";
    cout << "Выбор: ";
    cin >> x;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите число: ";
        cin >> x;
    }
    if (x == 1) p.repair = true;
    else if (x == 2) p.repair = false;
    else if (x != 0) cout << "Такого действия нет.\n";
}