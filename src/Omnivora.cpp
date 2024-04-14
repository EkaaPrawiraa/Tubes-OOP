#include "item/Omnivora.hpp"

Omnivora::Omnivora(const string &kodeHuruf,const string &name, const string &type, int weightToHarvest, int price, int berat, const string &location,  vector<Product*>  hasil) 
: Animal(kodeHuruf,  name, type, weightToHarvest, price, berat, location), hasilpanen(hasil){}

Omnivora::Omnivora(const Omnivora& other): Animal(other), hasilpanen(other.hasilpanen){}

Omnivora::~Omnivora(){}

vector<Product*> Omnivora::gethasilpanen() {
    return hasilpanen;
}

string Omnivora::getclassname(){
    return "Omnivora";
}