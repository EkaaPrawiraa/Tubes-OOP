#ifndef PETANI_HPP
#define PETANI_HPP
#include <string>
#include <iostream>
#include "PlantAnimal/Plant.hpp"
#include "Role.hpp"
using namespace std;
class Petani : public Role{
    private:
        vector<Plant> plant;

    public:
        Petani(string username, float weight, int uang);
        virtual ~Petani();
        virtual void next();
        virtual void membeli();
        virtual void menjual();
        void CetakLadang(int row, int col);
        void Tanam();
        void Memanen();
        virtual int calculate_tax()=0;
};


#endif