//BasicType\UV.cpp

#include "UV.hpp"

UV::UV() : u(0) , v(0) , s(0){}

bool UV::operator==( UV b ) const
{
    if(u == b.u)
        if(v == b.v)
            if(s == b.s)
                return true;
    return false;
}

bool operator<(UV a , UV b)
{
    if(a.u < b.u)
        return true;
    if(a.u == b.u)
    {
        if(a.v < b.v)
            return true;
        if(a.v == b.v)
            if(a.s < b.s)
                return true;
    }
    return false;
}
