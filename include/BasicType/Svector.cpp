//BasicType\Svector.cpp

#include"Svector.hpp"
#include<iostream>

using namespace std;

void Svector::print()
{
    cout << x << " ";
    cout << y << " ";
    cout << z << " ";
}

Svector Svector::operator=( Svector b )
{
    x = b.x;
    y = b.y;
    z = b.z;

    return *this;
}

Svector Svector::operator+( Svector b )
{
    return Svector(x + b.x ,y + b.y ,z + b.z);
}

bool Svector::operator==( Svector b )
{
    if(x == b.x)
        if(y == b.y)
            if(z == b.z)
                return true;
    return false;
}

Svector::operator Cvector()
{
    return Cvector(x,y,z);
}
