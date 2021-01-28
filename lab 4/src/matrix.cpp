#include <iostream>
#include <string>
#include "lab4_zuza/matrix.hpp"

using namespace std;

Matrix::Matrix(int y, int x)
{
    macierz = new double * [y];
    szerokosc=x;
    wysokosc=y;
    for (int i=0; i<y; i++)
        macierz[i] = new double [x];

    for (int i=0; i<y; i++)
        for(int j=0; j<x; j++)
            macierz[i][j]=0;

}
Matrix::Matrix(int x)
{
    macierz = new double * [x];
    szerokosc = wysokosc = x;
    for (int i=0; i<x; i++)
        macierz[i] = new double [x];

    for (int i=0; i<x; i++)
        for(int j=0; j<x; j++)
            macierz[i][j]=0;

}

Matrix::Matrix(string path)
{

    std::ifstream file;
    file.open (path);
    string x,y;
    getline (file,x);    getline (file,y);

    szerokosc = std::stoi(x);   wysokosc = std::stoi(y);

    //Inicializacja tabeli dynamicznej
    macierz = new double * [wysokosc];
    for (int i=0; i < wysokosc ; i++)
        macierz[i] = new double [szerokosc];



    //Przypisywanie wartosci z pliku
    for (int i=0; i<wysokosc ; i++)
        for (int j=0; j<szerokosc && getline(file, x); j++)
        {
            //cout <<x<<" "<<stod(x)<<"\t"<<macierz[i][j]<<"\n";
            macierz[i][j] = std::stod(x);
        }

    file.close();



}
void Matrix::print()
{
    cout<<"Printing matrix ("<<szerokosc<<","<<wysokosc<<"):"<<endl;
    for (int i=0; i<wysokosc; i++)
    {
        for(int j=0; j<szerokosc; j++)
            cout<<macierz[i][j]<<"\t";
        cout<<endl;
    }


}

void Matrix::set(int x, int y, double value)
{
    macierz[x-1][y-1] = value;
}

double Matrix::get(int x, int y)
{
    return macierz[x-1][y-1];
}

void Matrix::add(Matrix m)
{
    for (int i=0; i<m.wysokosc; i++)
    {
        for(int j=0; j<m.szerokosc; j++)
            macierz[i][j] += m.macierz[i][j];
    }

}

void Matrix::substract(Matrix m)
{
    for (int i=0; i<m.wysokosc; i++)
    {
        for(int j=0; j<m.szerokosc; j++)
            macierz[i][j] -= m.macierz[i][j];
    }

}

Matrix* Matrix::multiply(Matrix m)
{
    Matrix * pnt = new Matrix(wysokosc, m.szerokosc);
    double s=0.0;
    for (int i=0; i<wysokosc; i++)
    {
        for(int j=0; j<m.szerokosc; j++)
        {   s=0.0;
           for(int k=0; k<szerokosc; k++)
            {
                s += macierz[i][k]*m.macierz[k][j];
            }
            pnt->macierz[i][j]=s;
        }

    }
    return pnt;
}

int Matrix::cols()
{
    return szerokosc;
}

int Matrix::rows()
{
    return wysokosc;
}

void Matrix::store(std::string filename, std::string path)
{

    std::ofstream file;
    file.open (path , ios::in);

    std::string data = to_string(szerokosc)+"\n"+to_string(wysokosc)+"\n";
    for (int i=0; i<wysokosc; i++)
    {
        for(int j=0; j<szerokosc; j++)
            data += to_string(macierz[i][j]) + "\n";
    }
    file << data;

    file.close();
}
