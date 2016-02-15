#ifndef CACREAGE_HPP_INCLUDED
#define CACREAGE_HPP_INCLUDED

#include <iostream>

using namespace std;

class CAcreage
{
   public:
    float north;
    float south;
    float centre;
    float west;
    float east;

    CAcreage(float north , float west , float south , float east , float centre);
    float heightest(float x , float y);
    void recreate(float _north , float _west , float _south , float _east , float _centre);
    void print();
};

#endif // CACREAGE_HPP_INCLUDED
