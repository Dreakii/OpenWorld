//Plik: Cvector.cpp
#include "Cvector.hpp"

Cvector::Cvector(float x_ , float y_ , float z_)
{
    x = x_;
    y = y_;
    z = z_;
}

Cvector Cvector::operator+( const Cvector& b ) const
{
    return Cvector(x + b.x ,y + b.y ,z + b.z);
}

bool operator==( Cvector a , Cvector b )
{
    if( (a.x == b.x) and (a.y == b.y) and (a.z == b.z) )
        return true;
    else
        return false;
}

bool operator<(Cvector a , Cvector b)
{
    if(a.x < b.x)
        return true;
    if(a.x == b.x)
    {
        if(a.y < b.y)
            return true;
        if(a.y == b.y and a.z < b.z)
            return true;
    }
    return false;
}
