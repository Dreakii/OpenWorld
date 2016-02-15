#ifndef SVECTOR_HPP_INCLUDED
#define SVECTOR_HPP_INCLUDED

#include"Cvector.hpp"

class Svector // vector tablicowy
{
   public:
    int x;
    int y;
    int z;

    Svector(){};
    Svector(int _x , int _y , int _z) : x(_x) , y(_y) , z(_z){}
    void print();
    Svector operator=( Svector b );
    Svector operator+( Svector b );
    bool operator==( Svector b );
    operator Cvector();
};

#endif // SVECTOR_HPP_INCLUDED
