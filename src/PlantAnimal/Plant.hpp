#ifndef PLANT_HPP
#define PLANT_HPP

#include <vector>
#include <iostream>
#include "../Configuration/PlantConfig.hpp"
using namespace std;
class Plant {
    public:
        Plant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        Plant(const Plant&);
        ~Plant();
        void display() const;
        string getname() const;
        string getKode() const;
        std::string gettype();
        int getdurationtoharvest();
        int getprice();
        string getlocation() const;
        int getumur() const;
        int getprice() const;
        pair<char, int> getColumnAndRowIndex(const std::string& location) const;

    private:
        static int ID;
        string kodeHuruf;
        string name;
        string type;
        int durationToHarvest;
        int price;
        int umur;
        string location;
        vector<PlantConfig> Plants;
};

class MaterialPlant : public Plant {
    public:
        MaterialPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        MaterialPlant(const Plant&);
        ~MaterialPlant();
        int gethasilpanen();
    private:
        int hasilpanen;

};

class FruitPlant : public Plant {
    public:
        FruitPlant(const string &kodeHuruf,const string &name, const string &type, int durationToHarvest, int price, int umur, const string &location);
        FruitPlant(const Plant&);
        ~FruitPlant();
        int gethasilpanen();
    private:
        int hasilpanen;

};

#endif