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

void dobavitks(Station& s)
{
    cout << "Название КС: ";
    cin >> s.name;
    cout << "Всего цехов: ";
    cin >> s.workshops;
    while (cin.fail() || s.workshops <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите число больше 0: ";
        cin >> s.workshops;
    }
    cout << "Работающих цехов: ";
    cin >> s.working;
    while (cin.fail() || s.working < 0 || s.working > s.workshops)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите число от 0 до " << s.workshops << ": ";
        cin >> s.working;
    }
    cout << "Класс станции (1 или 2): ";
    cin >> s.stationClass;
    while (cin.fail() || (s.stationClass != 1 && s.stationClass != 2))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите 1 или 2: ";
        cin >> s.stationClass;
    }
}

void pokazatks(const Station& s)
{
    cout << "\nКомпрессорная станция\n";
    cout << "Название: " << s.name << "\n";
    cout << "Всего цехов: " << s.workshops << "\n";
    cout << "Работающих цехов: " << s.working << "\n";
    cout << "Класс: " << s.stationClass << "\n";
}

void izmenitks(Station& s)
{
    int x;
    cout << "\n1 - Запустить цех\n";
    cout << "2 - Остановить цех\n";
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
    if (x == 1)
    {
        if (s.working < s.workshops) s.working++;
        else cout << "Все цеха уже работают.\n";
    }
    else if (x == 2)
    {
        if (s.working > 0) s.working--;
        else cout << "Все цеха уже остановлены.\n";
    }
    else if (x != 0) cout << "Такого действия нет.\n";
}

void pokazatobekty(const Pipe& p, const Station& s)
{
    if (p.name.empty()) cout << "\nТруба отсутствует.\n";
    else pokazattrubu(p);
    if (s.name.empty()) cout << "\nКС отсутствует.\n";
    else pokazatks(s);
}

void sohranittrubu(ofstream& f, const Pipe& p)
{
    f << p.name << '\n' << p.length << '\n' << p.diameter << '\n' << p.repair << '\n';
}

void sohranitks(ofstream& f, const Station& s)
{
    f << s.name << '\n' << s.workshops << '\n' << s.working << '\n' << s.stationClass << '\n';
}

void sohranitdannie(const Pipe& p, const Station& s)
{
    string fileName;
    cout << "Имя файла: ";
    cin >> fileName;
    ofstream f(fileName);
    if (!f)
    {
        cout << "Ошибка открытия файла.\n";
        return;
    }
    sohranittrubu(f, p);
    sohranitks(f, s);
    cout << "Данные сохранены.\n";
}

void zagruzittrubu(ifstream& f, Pipe& p)
{
    f >> p.name >> p.length >> p.diameter >> p.repair;
}

void zagruzitks(ifstream& f, Station& s)
{
    f >> s.name >> s.workshops >> s.working >> s.stationClass;
}

void zagruzitdannie(Pipe& p, Station& s)
{
    string fileName;
    cout << "Имя файла: ";
    cin >> fileName;
    ifstream f(fileName);
    if (!f)
    {
        cout << "Файл не найден.\n";
        return;
    }
    zagruzittrubu(f, p);
    zagruzitks(f, s);
    if (f.fail()) cout << "Ошибка чтения файла.\n";
    else cout << "Данные загружены.\n";
}