//BasicType\mesh_vector.cpp

#include "mesh_vector.hpp"

bool mesh_vector::operator==(const mesh_vector &other) const
{
    if( (a == other.a) and (b == other.b) and (c == other.c) )
        return true;
    if( (a == other.a) and (c == other.b) and (a == other.c) )
        return true;
    if( (b == other.a) and (a == other.b) and (c == other.c) )
        return true;
    if( (b == other.a) and (c == other.b) and (a == other.c) )
        return true;
    if( (c == other.a) and (a == other.b) and (b == other.c) )
        return true;
    if( (c == other.a) and (b == other.b) and (a == other.c) )
        return true;
    return false;
}

