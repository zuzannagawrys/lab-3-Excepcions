#include <iostream>
#include "lab4_zuza/matrix.hpp"


int main()
{
    //std::string path = "C:\\Users\\zuza2\\Desktop\\Plik.txt";

    std::cout<<"\tProgram o macierzach "<<std::endl<<
    "1. Przy korzystaniu z funkcji set i get nalezy podac numer elemntu tak jakby pierwszy element to byl 1"<<std::endl<<std::endl;


    Matrix m1(3,4);
    Matrix m2(3);
    Matrix m3(5);
    Matrix m4(3);
    //m1 set
        m1.set (1,1,34.5); m1.set (1,2,34.5); m1.set (2,3,34.5);
    //m4 set:
        m4.set (1,1,0.44); m4.set (1,2,34.5); m4.set (2,1,1.5);
        m4.set (2,2,44.5); m4.set (2,1,4.5); m4.set (3,3,34.5);
    std::cout<<"\nMatrix m1 and m2 print(): \n";
    m1.print();
    m2.print();
    std::cout<<"\nMatriz m2 plus matrix m1, equals:\n";
    m2.add (m1);
    m2.print();
    
    std::cout<<"\nMatrix m3 and m2 print(): \n";
    m3.print();
    m2.print();
    std::cout<<"\nMatrix m3 minus m2, equals: \n";
    m3.substract (m2);
    m3.print();

    std::cout<<"\nMatrix m2 and m4 print(): \n";
    m2.print();
    m4.print();
    std::cout<<"\nMatrix m2 times m4, equals:\n";
    Matrix * pnt = (m2.multiply(m4));
    pnt->print();

    //std::string nazwa = "Plik.txt";
    //m3.store(nazwa, path);



    //Matrix m5(path);
    //m5.print();
    //œcie¿ka do wklejenia przez u¿ytkownika
    std::cout<<std::endl<<m1.get(1,1)<<std::endl;

    system("PAUSE");
}
