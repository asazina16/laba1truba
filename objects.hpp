#pragma once
#include <string>
#include <fstream>
using namespace std;

struct Pipe
{
    string name;
    double length;
    int diameter;
    bool repair;
};

struct Station
{
    string name;
    int workshops;
    int working;
    int stationClass;
};

void dobavittrubu(Pipe& p);
void pokazattrubu(const Pipe& p);
void redaktirovatrubu(Pipe& p);
void dobavitks(Station& s);
void pokazatks(const Station& s);
void izmenitks(Station& s);
void pokazatobekty(const Pipe& p, const Station& s);
void sohranittrubu(ofstream& f, const Pipe& p);
void sohranitks(ofstream& f, const Station& s);
void sohranitdannie(const Pipe& p, const Station& s);
void zagruzittrubu(ifstream& f, Pipe& p);
void zagruzitks(ifstream& f, Station& s);
void zagruzitdannie(Pipe& p, Station& s);