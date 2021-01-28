#include <iostream>
#include <fstream>

class Matrix {

public:
    double **macierz;
    int szerokosc, wysokosc;

    //Konstruktory
    Matrix(int x, int y);
    Matrix(int side);
    Matrix(std::string path);

    void print();
    void set(int x, int y, double value);
    double get(int x, int y);
    void add(Matrix m);
    void substract(Matrix m);
    Matrix* multiply(Matrix m);
    int cols();
    int rows();
    void store(std::string filename, std::string path);
};
