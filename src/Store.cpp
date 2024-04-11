#include "Store/Store.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// buat startgame karna plant dan animal tak hingga jumlahnya
Store::Store(const vector<Plant> &plants,const vector<Animal> &animals ){
    this->plants=plants;
    this->animals=animals;
}

// buat dari state txt
Store::Store(const vector<Building> &buildings,const vector<Plant> &plants,const vector<Animal> &animals,const vector<Product> &products)
{
    this->buildings=buildings;
    this->plants=plants;
    this->animals=animals;
    this->products=products;
}

Store::~Store(){
    this->buildings.clear();
    this->plants.clear();
    this->animals.clear();
    this->products.clear();
}

void Store::addBuilding(const Building addedBuilding)
{
    buildings.push_back(addedBuilding);
}
void Store::addPlant(const Plant addedPlant)
{
    plants.push_back(addedPlant);
}
void Store::addAnimal(const Animal addedAnimal)
{
    animals.push_back(addedAnimal);
}
void Store::addProduct(const Product addedProduct)
{
    products.push_back(addedProduct);
}
void Store::deleteBuilding(const Building deletedBuilding)
{
    auto it = std::find(buildings.begin(), buildings.end(), deletedBuilding);
    if (it != buildings.end()) {
        buildings.erase(it);
        
    } else {
        std::cout << "Building bernama" << deletedBuilding.getNama() << " tidak ditemukan." << std::endl;
    }
}
void Store::deletePlant(const Plant deletedPlant)
{
    auto it = std::find(plants.begin(), plants.end(), deletedPlant);
    if (it != plants.end()) {
        plants.erase(it);
        
    } else {
        std::cout << "Plant bernama" << deletedPlant.getname() << " tidak ditemukan." << std::endl;
    }
}
void Store::deleteAnimal(const Animal deletedAnimal)
{
    auto it = std::find(animals.begin(), animals.end(), deletedAnimal);
    if (it != animals.end()) {
        animals.erase(it);
        
    } else {
        std::cout << "Animal bernama" << deletedAnimal.getname() << " tidak ditemukan." << std::endl;
    }
}
void Store::deleteProduct(const Product deletedProduct)
{
    auto it = std::find(products.begin(), products.end(), deletedProduct);
    if (it !=products.end()) {
        products.erase(it);
        
    } else {
        std::cout << "Product bernama" << deletedProduct.getname() << " tidak ditemukan." << std::endl;
    }
}

void Store::display(){
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    
    map<string, int> countMap;

    for (const auto& building : buildings) {
        countMap[building.getNama()]++;
    }

    for (const auto& plant : plants) {
        countMap[plant.getname()]++;
    }

    for (const auto& animal : animals) {
        countMap[animal.getname()]++;
    }

    for (const auto& product : products) {
        countMap[product.getname()]++;
    }

    int count = 1;
    for (const auto& pair : countMap) {
        string kode = pair.first;
        int qty = pair.second;

        // Menampilkan harga berdasarkan kode barang
        int price = -1;
        for (const auto& building : buildings) {
            if (building.getNama() == kode) {
                price = building.getHarga();
                break;
            }
        }
        for (const auto& plant : plants) {
            if (plant.getname() == kode) {
                price = plant.getprice();
                break;
            }
        }
        for (const auto& animal : animals) {
            if (animal.getname() == kode) {
                price = animal.getprice();
                break;
            }
        }
        for (const auto& product : products) {
            if (product.getname() == kode) {
                price = product.getprice();
                break;
            }
        }

        cout << count << ". " << kode << " - " << price;
        
        // Menampilkan kuantitas jika lebih dari 1
        if (qty > 1) {
            cout << " (" << qty << ")";
        }
        
        cout << endl;
        count++;
    }
}


int Store::getPriceBuilding(const string kode) {
    for (const auto& building : buildings) {
        if (building.getKode() == kode) {
            return building.getHarga();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

int Store::getPricePlant(const string kode) {
    for (const auto& plant : plants) {
        if (plant.getKode() == kode) {
            return plant.getprice();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

int Store::getPriceAnimal(const string kode) {
    for (const auto& animal : animals) {
        if (animal.getkode() == kode) {
            return animal.getprice();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

int Store::getPriceProduct(const string kode) {
    for (const auto& product : products) {
        if (product.getkodeHuruf() == kode) {
            return product.getprice();
        }
    }
    return -1; // Mengembalikan -1 jika kode tidak ditemukan
}

int Store::buyItem(const string  kode, int quantity,int usersmoney)
{
    bool quantityEnough = true;
    int totalHarga =0;
    if (quantity <= 0 || usersmoney <= 0) {
        cout << "Quantity dan uang harus lebih dari 0." << endl;
        return 0;
    }
    for (Plant& plant : plants){
        if (plant.getKode() == kode)
        {
            totalHarga = plant.getprice()*quantity;
            goto exitLoop;
        }
    }
    for (Animal& animal : animals) {
        if (animal.getkode() == kode)
        {
            totalHarga = animal.getprice()*quantity;
            goto exitLoop;
        }
    for (Product& product : products)
    {
        if (product.getkodeHuruf() == kode)
        {
            if (getJumlah(product.getkodeHuruf())<quantity)
            {
                quantityEnough = false;
                goto exitLoop;
            }
            totalHarga = product.getprice()*quantity;
            if (totalHarga>usersmoney)
            {
                cout<<"Uang Anda kurang, gulden yang dibutuhkan : "<<totalHarga<<endl;
                return 0;
            }
            deleteProduct(product);
            goto exitLoop;
        }
    }
    for (Building& building : buildings)
    {
        if (building.getKode() == kode)
        {
            if (getJumlah(building.getKode())<quantity)
            {
                quantityEnough = false;
                goto exitLoop;
            }
            totalHarga = building.getHarga()*quantity;
            if (totalHarga>usersmoney)
            {
                cout<<"Uang Anda kurang, gulden yang dibutuhkan : "<<totalHarga<<endl;
                return 0;
            }
            deleteBuilding(building);
            goto exitLoop;
        }
    }
    exitLoop:
    if (!quantityEnough){
        // UNTUK QUANTITY ASKED MODE THAN THE STORE HAS
        cout<<"Quantity barang yang ingin dibeli tidak cukup."<<endl;
        return 0;
    }
    else if (totalHarga == 0){
        // untuk kode tidak ditemukan
        cout <<"Kode barang tidak terdapat di toko."<<endl;
        return 0;
    }
    else{
        return totalHarga;
    }
}


int Store::getJumlah(string kode) {
    int jumlah = 0;
    // Periksa jumlah building
    for (const Building& building : buildings) {
        if (building.getKode() == kode) {
            jumlah++;
        }
    }
    if (jumlah>0)
    {
        return jumlah;
    }
    // Periksa jumlah plant
    for (const Plant& plant : plants) {
        if (plant.getKode() == kode) {
            jumlah++;
        }
    }
    if (jumlah>0)
    {
        return jumlah;
    }
    // Periksa jumlah animal
    for (const Animal& animal : animals) {
        if (animal.getkode() == kode) {
            jumlah++;
        }
    }
    if (jumlah>0)
    {
        return jumlah;
    }

    // Periksa jumlah product
    for (const Product& product : products) {
        if (product.getkodeHuruf() == kode) {
            jumlah++;
        }
    }

    return jumlah;
}

