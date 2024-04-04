#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
using namespace std;

class Animal {
public:
    Animal(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location);
    Animal(const Animal&);
    ~Animal();

    string getname() const;
    string gettype();
    int getweighttoharvest();
    int getprice();
    int getberat();
    string getlocation();

protected:
    string kodeHuruf;
    string name;
    string type;
    int weightToHarvest;
    int price;
    int berat;
    string location;
};

class Herbivora : public Animal {
public:
    Herbivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location);
    Herbivora(const Animal&);
    ~Herbivora();
    int gethasilpanen();
private:
    int hasilpanen;
};

class Karnivora : public Animal {
public:
    Karnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location);
    Karnivora(const Animal&);
    ~Karnivora();
    int gethasilpanen();
private:
    int hasilpanen;
};

class Omnivora : public Animal {
public:
    Omnivora(const string &kodeHuruf, const string &name, const string &type, int weightToHarvest, int price, int berat, string location);
    Omnivora(const Animal&);
    ~Omnivora();
    int gethasilpanen();
private:
    int hasilpanen;
};

#endif
