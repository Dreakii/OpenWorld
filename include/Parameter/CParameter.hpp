#ifndef CPARAMETER_HPP_INCLUDED
#define CPARAMETER_HPP_INCLUDED

#include "CAcreage.hpp"
#include "../Graphics.hpp"

class CParameter // klasa Ustawien obiektu
{
   public:
    Cmodel part[6]; // tablica modeli
    CAcreage layer;

    bool conecting; // dane laczen
    bool con[6];
    bool conAB[6];
    bool conA[6];
    bool conB[6];

    CParameter();
    ~CParameter();
    CParameter& operator=(const CParameter& rm);

    void SetFromFile( string filename, int pos);
    void DownloadFromFile( string filename , int id);
    void RorateZ90(bool mod = false);
    void RorateZ180(bool mod = false);
    void RorateZ270(bool mod = false);
    bool IsConecting(); // sprawdza chcec laczenia sie obiektu
    void print();
};

#endif // CPARAMETER_HPP_INCLUDED
