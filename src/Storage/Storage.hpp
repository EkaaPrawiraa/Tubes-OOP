#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "..\\color\\pcolor.h" //Untuk print display

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<std::tuple<std::string, std::string, std::string>>> matrix; //KODE, COLOR, NamaTanaman ini kalau untuk matrix ladang, sesuain aja sama matrix kalian
    static int count;

public:
    Matrix(int rows = 0, int cols = 0);

    std::tuple<std::string, std::string, std::string> get(char key, int index) const;
    void set(char key, int index, std::string value, std::string color, std::string other);
    void del(char key, int index);
    void setfirstempty(std::string value, std::string color, std::string other);

    int getRows() const;
    int getCols() const;
    int getSize() const;
    int CountElement() const;
    std::vector<std::pair<std::string, int>> getCodeCounts();

    void display(std::string tipe) const;
};

#endif 
